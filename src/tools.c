/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 20:49:06 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/23 21:06:16 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_stats(t_fdf *fdf)
{
	ft_putstr("x = ");
	ft_putnbr(fdf->sizex);
	ft_putchar('\n');
	ft_putstr("y = ");
	ft_putnbr(fdf->sizey);
	ft_putchar('\n');
}

void	print_vector_map(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->sizey)
	{
		j = 0;
		while (j < fdf->sizex)
		{
			printf("(%d, %d, %d)\t", fdf->map[i][j].x, fdf->map[i][j].y, fdf->map[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}