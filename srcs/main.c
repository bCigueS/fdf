/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:48:54 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/19 10:43:05 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (error_usg());
	else
	{
		if (fdf_parsing(argv[1], &fdf) != 0)
			return (error_parsing());
		if (fdf_init(&fdf) != 0)
			return (error_fdf());
		menu_print();
		render(&fdf);
		mlx_hook(fdf.win_ptr, KEY_PRESS, (1L << 0), &handle_key, &fdf);
		mlx_hook(fdf.win_ptr, EXIT, 0, &quit, &fdf);
		mlx_loop(fdf.mlx_ptr);
		clean_map(fdf.map.map, fdf.map.row);
		clean_map(fdf.map.color, fdf.map.row);
		clean_fdf(&fdf);
	}
	return (0);
}
