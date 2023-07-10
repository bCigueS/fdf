/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:08:59 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/18 09:53:02 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_line	init_line(t_point p1, t_point p2)
{
	t_line	line;

	line.ex = ft_abs(p2.x - p1.x);
	line.ey = ft_abs(p2.y - p1.y);
	line.dx = 2 * line.ex;
	line.dy = 2 * line.ey;
	line.len_x = line.ex;
	line.len_y = line.ey;
	line.x_inc = 1;
	line.y_inc = 1;
	if (p1.x > p2.x)
		line.x_inc = -1;
	if (p1.y > p2.y)
		line.y_inc = -1;
	line.x = p1.x;
	line.y = p1.y;
	line.color = p1.color;
	return (line);
}

void	bresenham_1(t_line line, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= line.len_x)
	{
		draw_pixel(fdf, (t_pixel){line.x, line.y, line.color});
		i++;
		line.x += line.x_inc;
		line.ex -= line.dy;
		if (line.ex < 0)
		{
			line.y += line.y_inc;
			line.ex += line.dx;
		}
	}
}

void	bresenham_2(t_line line, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= line.len_y)
	{
		draw_pixel(fdf, (t_pixel){line.x, line.y, line.color});
		i++;
		line.y += line.y_inc;
		line.ey -= line.dx;
		if (line.ey < 0)
		{
			line.x += line.x_inc;
			line.ey += line.dy;
		}
	}
}

void	draw_line(t_line line, t_fdf *fdf)
{
	if (line.len_x > line.len_y)
		bresenham_1(line, fdf);
	if (line.len_x < line.len_y)
		bresenham_2(line, fdf);
}

void	init_drawing(t_fdf *fdf, int y, int x, int dir)
{
	t_point	p1;
	t_point	p2;

	if (dir == 1)
	{
		p1 = init_point(fdf->map, y, x);
		p2 = init_point(fdf->map, y, x + 1);
		draw_line(init_line(p1, p2), fdf);
	}
	else if (dir == 0)
	{
		p1 = init_point(fdf->map, y, x);
		p2 = init_point(fdf->map, y + 1, x);
		draw_line(init_line(p1, p2), fdf);
	}
}
