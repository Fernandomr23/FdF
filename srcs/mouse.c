/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:06:42 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 16:04:26 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_zoom(int button, t_fdf *data)
{
	if (button == MOUSE_WHEEL_UP)
		data->camera->zoom += 2;
	else if (button == MOUSE_WHEEL_DOWN)
		data->camera->zoom -= 2;
	if (data->camera->zoom < 1)
		data->camera->zoom = 1;
	draw(data->map, data);
}

int	ft_mouse_down(int button, int x, int y, void *params)
{
	t_fdf	*data;

	data = (t_fdf *)params;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
		ft_zoom(button, data);
	else if (button == MOUSE_CLICK_LEFT || button == MOUSE_CLICK_RIGHT
		|| button == MOUSE_CLICK_MIDDLE)
	{
		data->mouse->button = button;
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
	}
	return (0);
}

int	ft_mouse_up(int button, int x, int y, void *params)
{
	t_fdf	*data;

	(void)x;
	(void)y;
	data = (t_fdf *)params;
	if (button == MOUSE_CLICK_LEFT || button == MOUSE_CLICK_RIGHT
		|| button == MOUSE_CLICK_MIDDLE)
		data->mouse->button = 0;
	return (0);
}

static void	ft_move_z(int x, int y, t_fdf *data)
{
	if (x < (WIDTH / 2) + data->camera->x_offset)
		data->camera->z_angle -= (y - data->mouse->prev_y) * 0.002;
	else
		data->camera->z_angle += (y - data->mouse->prev_y) * 0.002;
	if (data->camera->z_angle < -10)
		data->camera->z_angle = -10;
	else if (data->camera->z_angle > 10)
		data->camera->z_angle = 10;
	data->mouse->prev_x = x;
	data->mouse->prev_y = y;
	draw(data->map, data);
}

int	ft_mouse_move(int x, int y, void *params)
{
	t_fdf	*data;

	data = (t_fdf *)params;
	if (data->mouse->button == MOUSE_CLICK_RIGHT)
	{
		data->camera->x_angle += (y - data->mouse->prev_y) * 0.002;
		data->camera->y_angle += (x - data->mouse->prev_x) * 0.002;
		data->camera->x_angle = ft_reset_angles(data->camera->x_angle);
		data->camera->y_angle = ft_reset_angles(data->camera->y_angle);
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
		draw(data->map, data);
	}
	else if (data->mouse->button == MOUSE_CLICK_LEFT)
	{
		data->camera->x_offset += (x - data->mouse->prev_x);
		data->camera->y_offset += (y - data->mouse->prev_y);
		data->mouse->prev_x = x;
		data->mouse->prev_y = y;
		draw(data->map, data);
	}
	else if (data->mouse->button == MOUSE_CLICK_MIDDLE)
		ft_move_z(x, y, data);
	return (0);
}
