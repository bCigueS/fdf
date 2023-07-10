/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:56:16 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 10:48:25 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_PLUS)
		fdf->map.zoom += 1;
	else if (key == MAIN_PAD_MINUS)
		fdf->map.zoom -= 1;
	if (fdf->map.zoom < 1)
		fdf->map.zoom = 1;
	render(fdf);
}

void	iso_ortho(int key, t_fdf *fdf)
{
	if (key == 0x0069)
		fdf->map.iso = 1;
	if (key == 0x0070)
		fdf->map.iso = 0;
	render(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == 0xff51)
		fdf->map.x_offset -= 10;
	if (key == 0xff53)
		fdf->map.x_offset += 10;
	if (key == 0xff52)
		fdf->map.y_offset -= 10;
	if (key == 0xff54)
		fdf->map.y_offset += 10;
	render(fdf);
}

void	z_modif(int key, t_fdf *fdf)
{
	if (key == 0x0077)
		fdf->map.z_manip -= 1;
	if (key == 0x0073)
		fdf->map.z_manip += 1;
	render(fdf);
}

int	handle_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		mlx_loop_end(fdf->mlx_ptr);
	if (keycode == MAIN_PAD_PLUS || keycode == MAIN_PAD_MINUS)
		zoom(keycode, fdf);
	if (keycode == 0x0069 || keycode == 0x0070)
		iso_ortho(keycode, fdf);
	if (keycode == 0xff51 || keycode == 0xff53
		|| keycode == 0xff52 || keycode == 0xff54)
		move(keycode, fdf);
	if (keycode == 0x0077 || keycode == 0x0073)
		z_modif(keycode, fdf);
	if (keycode == 0x0072)
	{
		init_dimension_map(&fdf->map);
		render(fdf);
	}
	return (0);
}
