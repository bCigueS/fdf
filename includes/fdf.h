/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:55:07 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 10:42:52 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//  Includes
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

// # define FT_ABS(X) (((X < 0) ? (-X) : (X)))
//  Mask
// # define NO_EVENT_MASK 0
// # define KEY_PRESS_MASK 1L<<0
// # define KEY_RELEASE_MASK 1L<<1
// # define BUTTON_PRESS_MASK 1L<<2
// # define BUTTON_RELEASE_MASK 1L<<3

// Event
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define EXIT 17

// Key
# define KEY_ESC 65307
# define MAIN_PAD_PLUS 0x003d 
# define MAIN_PAD_MINUS 0x002d

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;

typedef struct s_map
{
	int		**map;
	int		**color;
	int		column;
	int		row;
	int		width;
	int		height;
	int		zoom;
	int		max_z;
	int		min_z;
	int		mid_z;
	int		x_offset;
	int		y_offset;
	int		z_manip;
	int		iso;
}				t_map;

typedef struct s_line
{
	int		ex;
	int		ey;
	int		dx;
	int		dy;
	int		len_x;
	int		len_y;
	int		x_inc;
	int		y_inc;
	int		x;
	int		y;
	int		color;
}				t_line;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}				t_fdf;

//	Error Functions
int		error_usg(void);
int		error_parsing(void);
int		error_fdf(void);

//	Parsing
int		fdf_parsing(char *argv, t_fdf *fdf);
int		map_size(int fd, t_map *map);
int		color_info(char *value);
void	init_dimension_map(t_map *map);
void	find_middle_z(t_fdf *fdf);

//	Clean
void	clean_map(int **map, int index);
void	clean_tab_line(char **tab, char *line, int index);
void	clean_tab(char **tab, int index);
int		close_file(int fd);

//	FDF
int		fdf_init(t_fdf *fdf);
int		handle_key(int keycode, void *param);
void	clean_fdf(t_fdf *fdf);
int		quit(t_fdf *fdf);

// Point
void	scale_point(t_map map, t_point *point);
void	turn_to_iso(t_point *point);
t_point	init_point(t_map map, int y, int x);

//	Drawing
void	draw_pixel(t_fdf *fdf, t_pixel pix);
void	draw_background(t_fdf *fdf);
void	init_drawing(t_fdf *fdf, int y, int x, int dir);
void	render(t_fdf *fdf);

//	Utils
int		ft_abs(int x);
void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	iso_ortho(int key, t_fdf *fdf);
void	clean_gnl(int fd, char **line);
void	menu_print(void);

#endif
