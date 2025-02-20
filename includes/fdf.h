/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:52 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 15:55:12 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define MINUS 45
# define PLUS 43
# define SPACE 32
# define KEY_R 114
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 65307

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}				t_point;

typedef struct s_map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
	int		iso;
}	t_camera;

typedef struct s_mouse
{
	int	button;
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
}	t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}	t_fdf;

void	read_file(char *file_name, t_map *map);
void	draw(t_map *map, t_fdf *data);
int		words_count(char *line, char c);
void	ft_free_matrix(char **num, int i);
void	ft_put_pixel(t_fdf *data, int x, int y, int color);
void	draw_line(t_point s, t_point e, t_fdf *data);
t_point	project(int x, int y, t_fdf *data);
int		ft_min(int a, int b);
int		get_default_color(int z, t_map *map);
void	ft_error(char *str);
double	ft_reset_angles(double angle);
float	ft_abs(float n);
int		ft_ipart(float n);
float	ft_fpart(float n);
float	ft_rfpart(float n);
void	ft_controls(t_fdf *data);
int		ft_key_press(int keycode, void *params);
int		ft_mouse_down(int button, int x, int y, void *params);
int		ft_mouse_up(int button, int x, int y, void *params);
int		ft_mouse_move(int x, int y, void *params);
int		ft_close_win(void *params);

#endif