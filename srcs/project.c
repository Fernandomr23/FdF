/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:31:17 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 16:15:52 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

t_point	project(int x, int y, t_fdf *data)
{
	t_point	point;

	point.z = data->map->array[y][x][0];
	if (data->map->array[y][x][1] >= 0)
		point.color = data->map->array[y][x][1];
	else
		point.color = get_default_color(data->map->array[y][x][0], data->map);
	point.x = x * data->camera->zoom;
	point.y = y * data->camera->zoom;
	point.z *= data->camera->zoom / data->camera->z_height;
	point.x -= (data->map->width * data->camera->zoom) / 2;
	point.y -= (data->map->height * data->camera->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, data->camera->x_angle);
	ft_rotate_y(&point.x, &point.z, data->camera->y_angle);
	ft_rotate_z(&point.x, &point.y, data->camera->z_angle);
	point.x += WIDTH / 2 + data->camera->x_offset;
	point.y += (HEIGHT + data->map->height / 2 * data->camera->zoom) / 2
		+ data->camera->y_offset;
	point.reverse = 0;
	return (point);
}
