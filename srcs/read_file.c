/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:49 by fmorenil          #+#    #+#             */
/*   Updated: 2024/08/01 19:58:30 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Invalid FD");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		first_w;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	first_w = words_count(line, ' ');
	while (line)
	{
		width = words_count(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (first_w);
}

void	fill_matrix(int **z, char *line, int width)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	if (!num)
		ft_error("Split Error");
	i = 0;
	while (num[i] && i < width)
	{
		z[i] = ft_calloc(2, sizeof(int));
		if (!z[i])
			ft_error("Malloc error");
		z[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			z[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			z[i][1] = -1;
		free(num[i++]);
	}
	ft_free_matrix(num, i);
}

static void	ft_z_min_max(t_map *map)
{
	int	i;
	int	j;

	map->z_max = map->array[0][0][0];
	map->z_min = map->array[0][0][0];
	i = 0;
	while (i < map->height)
	{
		if (!map->array[i])
			ft_error("Invalid map");
		j = 0;
		while (j < map->width)
		{
			if (!map->array[i][j])
				ft_error("Invalid map");
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	read_file(char *file_name, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	map->height = get_height(file_name);
	map->width = get_width(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	map->array = ft_calloc(map->height, sizeof(int **));
	if (!map->array)
		ft_error("Malloc error");
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		map->array[++i] = ft_calloc(map->width, sizeof(int *));
		if (!map->array[i])
			ft_error("Malloc error");
		fill_matrix(map->array[i], line, map->width);
		(free(line), line = get_next_line(fd));
	}
	(free(line), ft_z_min_max(map), close(fd));
}
