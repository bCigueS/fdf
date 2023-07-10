/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:15:20 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 09:07:26 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	map_size(int fd, t_map *map)
{
	char	*line;
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (++y)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		x = 0;
		tab = ft_split(line, " \n");
		while (tab[x++] != NULL)
			;
		clean_tab_line(tab, line, x);
		if (y == 1)
			map->column = x;
		else if (map->column != x)
			return (clean_gnl(fd, &line), 1);
	}
	map->column = --x;
	map->row = --y;
	return (0);
}

int	init_map_color(t_map *map)
{
	int	x;

	map->map = (int **)malloc(sizeof(int *) * map->row);
	if (map->map == NULL)
		return (1);
	map->color = (int **)malloc(sizeof(int *) * map->row);
	if (map->color == NULL)
		return (1);
	x = 0;
	while (x < map->row)
	{
		map->map[x] = (int *)ft_calloc(map->column, sizeof(int));
		if (map->map[x] == NULL)
			return (clean_map(map->map, x), clean_map(map->color, x), 1);
		map->color[x] = (int *)ft_calloc(map->column, sizeof(int));
		if (map->color[x] == NULL)
			return (clean_map(map->map, x), clean_map(map->color, x), 1);
		x++;
	}
	return (0);
}

void	set_value(t_map *map, char **tab, int index)
{
	char	*temp_color;
	char	**split_c;
	int		x;

	x = 0;
	while (tab[x] != NULL)
	{
		if (color_info(tab[x]) == 0)
		{
			map->map[index][x] = ft_atoi(tab[x]);
			map->color[index][x] = 0xFFFFFF;
			x++;
		}
		else
		{
			split_c = ft_split(tab[x], ",");
			temp_color = split_c[1] + 2;
			map->map[index][x] = ft_atoi(split_c[0]);
			map->color[index][x] = ft_atoi_base(temp_color, 16);
			x++;
			clean_tab(split_c, 2);
		}
	}
}

void	init_values(int fd, t_map *map)
{
	char	*line;
	char	**tab;
	int		x;

	x = 0;
	while (x < map->row + 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tab = ft_split(line, " \n");
		set_value(map, tab, x);
		clean_tab_line(tab, line, map->column);
		x++;
	}
}

int	fdf_parsing(char *argv, t_fdf *fdf)
{
	int	fd;

	if (argv == NULL)
		return (1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	if (map_size(fd, &fdf->map) != 0)
		return (1);
	if (fdf->map.column < 0 || fdf->map.row < 0)
		return (1);
	if (close_file(fd) == 1)
		return (1);
	init_map_color(&fdf->map);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	init_values(fd, &fdf->map);
	if (close_file(fd) == 1)
		return (1);
	init_dimension_map(&fdf->map);
	find_middle_z(fdf);
	return (0);
}
