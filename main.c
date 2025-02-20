/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:13 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/31 17:32:57 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static t_fdf	*ft_init(const char *file_name)
{
	t_fdf	*data;
	char	*title;

	title = ft_strjoin("FdF - ", file_name);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_error("Data Malloc error");
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error("Connection error");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	if (!data->win)
		ft_error("Window error");
	free(title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_error("Image error");
	data->data_addr = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	data->map = NULL;
	data->camera = NULL;
	data->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!data->mouse)
		ft_error("Mouse error");
	return (data);
}

static t_camera	*ft_camera_init(t_fdf *data)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_error("Malloc error");
	camera->zoom = ft_min(WIDTH / data->map->width / 2,
			HEIGHT / data->map->height / 2);
	camera->x_angle = -0.615472907;
	camera->y_angle = -0.523599;
	camera->z_angle = 0.615472907;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	data->mouse->button = 0;
	data->mouse->prev_x = 0;
	data->mouse->prev_y = 0;
	return (camera);
}

static t_map	*ft_map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("Map error");
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map.fdf>\n", argv[0]);
		return (1);
	}
	data = ft_init(argv[1]);
	data->map = ft_map_init();
	read_file(argv[1], data->map);
	data->camera = ft_camera_init(data);
	ft_controls(data);
	draw(data->map, data);
	mlx_loop(data->mlx);
}
