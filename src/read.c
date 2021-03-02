/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/22 17:24:02 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/23 22:29:17 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		**read_map(t_fdf *fdf, int fd, int size)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * size);
	if (temp == NULL)
		return (NULL);
	while (ft_get_next_line(fd, &temp[i]) == 1)
	{
		if (ft_count_words(temp[i]) > fdf->sizex)
			fdf->sizex = ft_count_words(temp[i]);
		i++;
	}
	return (temp);
}

void		make_map(t_fdf *fdf, char **cmap)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	fdf->map = (t_vector**)malloc(sizeof(t_vector*) * fdf->sizey);
	while (i < fdf->sizey)
	{
		j = 0;
		fdf->map[i] = (t_vector*)malloc(sizeof(t_vector) * fdf->sizex);
		temp = ft_strsplit(cmap[i], ' ');
		free(cmap[i]);
		while (temp[j])
		{
			fdf->map[i][j].x = (j - (fdf->sizex / 2)) * 10;
			fdf->map[i][j].z = (i - (fdf->sizey / 2)) * 10;
			fdf->map[i][j].y = ft_atoi(temp[j]);
			j++;
			free(temp[j]);
		}
		free(temp);
		i++;
	}
	free(cmap);
}
