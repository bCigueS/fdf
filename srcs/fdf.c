/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:23:05 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/18 10:51:50 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		return (1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->map.width,
			fdf->map.height, "fdf");
	if (fdf->win_ptr == NULL)
		return (1);
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, fdf->map.width, fdf->map.height);
	if (fdf->img.img == NULL)
		return (1);
	fdf->img.addr = (int *)mlx_get_data_addr(
			fdf->img.img, &fdf->img.bpp, &fdf->img.line_len, &fdf->img.endian);
	if (fdf->img.addr == NULL)
		return (1);
	return (0);
}

void	find_middle_z(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map.row)
	{
		x = -1;
		while (++x < fdf->map.column)
		{
			if (fdf->map.map[y][x] > fdf->map.max_z)
				fdf->map.max_z = fdf->map.map[y][x];
			if (fdf->map.map[y][x] < fdf->map.min_z)
				fdf->map.min_z = fdf->map.map[y][x];
		}
		y++;
	}
	fdf->map.mid_z = (fdf->map.min_z + fdf->map.max_z) / 2 - 1;
}

int	quit(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx_ptr);
	return (0);
}

void	render(t_fdf *fdf)
{
	int		x;
	int		y;
	int		dir;

	draw_background(fdf);
	y = -1;
	while (++y < fdf->map.row)
	{
		dir = 1;
		x = -1;
		while (++x < fdf->map.column - 1)
			init_drawing(fdf, y, x, dir);
	}
	x = -1;
	while (++x < fdf->map.column)
	{
		dir = 0;
		y = -1;
		while (++y < fdf->map.row - 1)
			init_drawing(fdf, y, x, dir);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
}
