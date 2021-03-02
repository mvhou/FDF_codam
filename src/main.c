/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 14:44:09 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/23 21:05:55 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "Error opening file\n", 19);
			return (0);
		}
		fdf = initialize_fdf();
		fd = open(argv[1], O_RDONLY);
		check_size(fdf, fd);
		fd = open(argv[1], O_RDONLY);
		make_map(fdf, read_map(fdf, fd, fdf->sizey));
		print_stats(fdf);
		print_vector_map(fdf);
	}
	else
		write(1, "usage: ./fdf source_file\n", 25);
	return (0);
}
