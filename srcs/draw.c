/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:33:10 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 16:08:23 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_instructions(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 5, 0, 0xFFFFFF,
		"Left CLick:		Pan");
	mlx_string_put(data->mlx, data->win, 5, 20, 0xFFFFFF,
		"Right CLick:		Rotate x / y");
	mlx_string_put(data->mlx, data->win, 5, 40, 0xFFFFFF,
		"Middle CLick:		Rotate z");
	if (data->camera->iso)
		mlx_string_put(data->mlx, data->win, 5, 60, 0xFFFFFF,
			"Space:		Toggle projection (Current: Isometric)");
	else
		mlx_string_put(data->mlx, data->win, 5, 60, 0xFFFFFF,
			"Space:		Toggle projection (Current: Parallel)");
	mlx_string_put(data->mlx, data->win, 5, 80, 0xFFFFFF,
		"R: 	Reset");
	mlx_string_put(data->mlx, data->win, 5, 100, 0xFFFFFF,
		"-/+:		Flatten");
}

void	draw(t_map *map, t_fdf *data)
{
	int	x;
	int	y;

	ft_bzero(data->data_addr, WIDTH * HEIGHT * (data->bpp / 8));
	y = 0;
	if (data->camera->x_angle > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
	{
		x = 0;
		if (data->camera->y_angle > 0)
			x = map->width - 1;
		while (x < map->width && x >= 0)
		{
			if (x != map->width - 1)
				draw_line(project(x, y, data), project(x + 1, y, data), data);
			if (y != map->height - 1)
				draw_line(project(x, y, data), project(x, y + 1, data), data);
			x += -2 * (data->camera->y_angle > 0) + 1;
		}
		y += -2 * (data->camera->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_draw_instructions(data);
}
