/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:55:05 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/31 12:27:01 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_reset(t_fdf *data)
{
	data->camera->x_offset = 0;
	data->camera->y_offset = 0;
	if (data->camera->iso)
	{
		data->camera->x_angle = -0.615472907;
		data->camera->y_angle = -0.523599;
		data->camera->z_angle = 0.615472907;
	}
	else
	{
		data->camera->x_angle = -0.523599;
		data->camera->y_angle = -0.261799;
		data->camera->z_angle = 0;
	}
	data->camera->z_height = 1;
	data->camera->zoom = ft_min(WIDTH / data->map->width / 2,
			HEIGHT / data->map->height / 2);
}

static void	ft_toggle_projection(t_fdf *data)
{
	if (data->camera->iso)
	{
		data->camera->x_angle = -0.523599;
		data->camera->y_angle = -0.261799;
		data->camera->z_angle = 0;
	}
	else
	{
		data->camera->x_angle = -0.615472907;
		data->camera->y_angle = -0.523599;
		data->camera->z_angle = 0.615472907;
	}
	data->camera->iso = !data->camera->iso;
}

static void	ft_mod_height(int keycode, t_fdf *data)
{
	if (keycode == MINUS)
		data->camera->z_height += 0.1;
	else if (keycode == PLUS)
		data->camera->z_height -= 0.1;
	if (data->camera->z_height < 0.5)
		data->camera->z_height = 0.5;
	else if (data->camera->z_height > 10)
		data->camera->z_height = 10;
}

static void	ft_translate(int keycode, t_fdf *param)
{
	if (keycode == ARROW_LEFT)
		param->camera->x_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		param->camera->x_offset += 10;
	else if (keycode == ARROW_DOWN)
		param->camera->y_offset += 10;
	else if (keycode == ARROW_UP)
		param->camera->y_offset -= 10;
}

int	ft_key_press(int keycode, void *params)
{
	t_fdf	*param;

	param = (t_fdf *)params;
	if (keycode == ARROW_DOWN || keycode == ARROW_LEFT || keycode == ARROW_UP
		|| keycode == ARROW_RIGHT)
		ft_translate(keycode, param);
	else if (keycode == MINUS || keycode == PLUS)
		ft_mod_height(keycode, param);
	else if (keycode == SPACE)
		ft_toggle_projection(param);
	else if (keycode == KEY_R)
		ft_reset(param);
	else if (keycode == ESCAPE)
		ft_close_win(param);
	draw(param->map, param);
	return (0);
}
