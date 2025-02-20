/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:38:47 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 16:03:14 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_win(void *params)
{
	t_fdf	*data;
	int		x;
	int		y;

	data = (t_fdf *)params;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->camera);
	free(data->mouse);
	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
			free(data->map->array[y][x]);
		free(data->map->array[y]);
	}
	free(data->map->array);
	free(data->map);
	free(data->mlx);
	free(data);
	exit(0);
}

void	ft_controls(t_fdf *data)
{
	mlx_hook(data->win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win, 4, 1L << 2, ft_mouse_down, data);
	mlx_hook(data->win, 5, 1L << 3, ft_mouse_up, data);
	mlx_hook(data->win, 6, 1L << 6, ft_mouse_move, data);
	mlx_hook(data->win, 17, 0, ft_close_win, data);
}

double	ft_reset_angles(double angle)
{
	if (angle >= M_PI)
		return (-2 * M_PI - angle);
	else if (angle <= -M_PI)
		return (2 * M_PI + angle);
	return (angle);
}
