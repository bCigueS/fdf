/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:02:51 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/17 16:50:56 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clean_tab_line(char **tab, char *line, int index)
{
	int	x;

	x = 0;
	while (x < index && tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
	free(line);
}

void	clean_map(int **map, int index)
{
	int	x;

	x = 0;
	while (x < index && map[x] != NULL)
	{
		free(map[x]);
		x++;
	}
	free(map);
}

void	clean_tab(char **tab, int index)
{
	int	x;

	x = 0;
	while (x < index && tab[x] != NULL)
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

void	clean_fdf(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
}
