/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:08:50 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 10:47:36 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_background(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			draw_pixel(fdf, (t_pixel){x, y, 0x000000});
			x++;
		}
		y++;
	}
}

void	clean_gnl(int fd, char **line)
{
	while (*line != NULL)
	{
		*line = get_next_line(fd);
		free(*line);
	}
}

void	menu_print(void)
{
	ft_printf("FDF -- sbeylot Command\n");
	ft_printf("------------------------\n");
	ft_printf("Perspective type:\nIso = i\n Ortho = p\n");
	ft_printf("------------------------\n");
	ft_printf("Move:\nLeft = left arrow\nRight = right arrow\n");
	ft_printf("Up = Up arrow\nDown = down arrow\n");
	ft_printf("------------------------\n");
	ft_printf("Zoom:\nZoom in = +\nZoom out = -\n");
	ft_printf("------------------------\n");
	ft_printf("Z Value:\nReduce = w\nIncrease = s\n");
	ft_printf("------------------------\n");
	ft_printf("Reset Map = r\n");
	ft_printf("------------------------\n");
}
