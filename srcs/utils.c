/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:03:43 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 16:16:27 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_fdf *data, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * data->bpp / 8) + (y * data->size_line);
		data->data_addr[i] = color;
		data->data_addr[++i] = color >> 8;
		data->data_addr[++i] = color >> 16;
	}
}

void	ft_get_z_min_max(t_map *map, int n)
{
	if (n > map->z_max)
		map->z_max = n;
	if (n < map->z_min)
		map->z_min = n;
}

void	ft_error(char *str)
{
	perror(str);
	exit (-1);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_max - map->z_min;
	if (max == 0)
		return (0x333333);
	percent = ((double)(z - map->z_min) / max);
	if (percent < 0.2)
		return (0x333333);
	else if (percent < 0.4)
		return (0x666666);
	else if (percent < 0.6)
		return (0x999999);
	else if (percent < 0.8)
		return (0xA1CC2A);
	else
		return (0xC9FF3F);
}
