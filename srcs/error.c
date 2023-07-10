/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeylot <sbeylot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:10:16 by sbeylot           #+#    #+#             */
/*   Updated: 2022/08/16 10:19:15 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error_usg(void)
{
	ft_printf("Usage: ./fdf <fdf.map>\n");
	return (1);
}

int	error_parsing(void)
{
	ft_printf("Error in parsing, invalid map\n");
	return (1);
}

int	error_fdf(void)
{
	ft_printf("Error in fdf/mlx\n");
	return (1);
}
