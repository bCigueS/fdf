/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:05:05 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 10:25:54 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_file(int fd)
{
	if (close(fd) < 0)
		return (1);
	return (0);
}

int	color_info(char *value)
{
	int	x;

	x = 0;
	while (value[x])
	{
		if (value[x] == ',')
			return (1);
		x++;
	}
	return (0);
}

void	init_dimension_map(t_map *map)
{
	map->width = 1280;
	map->height = 720;
	if (map->column <= map->row)
		map->zoom = map->width / map->column / 2;
	else
		map->zoom = map->height / map->row / 2;
	map->mid_z = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->iso = 1;
	map->x_offset = 0;
	map->y_offset = 0;
	map->z_manip = 0;
}

void	draw_pixel(t_fdf *fdf, t_pixel pix)
{
	if ((pix.x >= 0 && pix.x < fdf->map.width)
		&& (pix.y >= 0 && pix.y < fdf->map.height))
			fdf->img.addr[pix.x + fdf->map.width * pix.y] = pix.color;
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
