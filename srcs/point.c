/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:54:08 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 10:30:00 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale_point(t_map map, t_point *point)
{
	point->x *= map.zoom;
	point->y *= map.zoom;
	point->z *= map.zoom + map.z_manip;
}

void	turn_to_iso(t_point *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_y) * cos(0.523599);
	point->y = (prev_x + prev_y) * sin(0.523599) - point->z;
}

void	turn_to_parra(t_point *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(0.785398);
	point->y = prev_y * sin(0.785398) - point->z;
}

t_point	init_point(t_map map, int y, int x)
{
	t_point	point;

	point = (t_point){x, y, map.map[y][x], 0};
	point.x -= map.column / 2;
	point.y -= map.row / 2;
	point.z -= map.mid_z;
	scale_point(map, &point);
	if (map.iso == 1)
		turn_to_iso(&point);
	else
		turn_to_parra(&point);
	point.x += (map.width / 2) + map.x_offset;
	point.y += (map.height / 2) + map.y_offset;
	point.color = map.color[y][x];
	return (point);
}
