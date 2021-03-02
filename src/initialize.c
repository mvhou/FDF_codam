/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 21:28:23 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/23 21:04:54 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			check_size(t_fdf *fdf, int fd)
{
	char	*line;
	int		ret;

	fdf->sizey = -1;
	ret = 1;
	while (ret == 1)
	{
		ret = ft_get_next_line(fd, &line);
		fdf->sizey++;
	}
	if (ret < 0)
		return (-1);
	close(fd);
	return (0);
}

void		initialize_cam(t_fdf *fdf)
{
	fdf->cam.zoom = 1;
	fdf->cam.pos.x = 0;
	fdf->cam.pos.y = 0;
	fdf->cam.pos.z = -10;
}

t_fdf		*initialize_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1024, 768, "FDF");
	initialize_cam(fdf);
	return (fdf);
}
