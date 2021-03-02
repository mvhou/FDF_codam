/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 22:48:47 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/23 22:49:44 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"

# define WIN_X 1024
# define WIN_Y 768

# define POINT_IS_IN_WINDOW (p0.x > 0 && p0.x < WIN_X + 1 && p0.y > 0 && p0.y < WIN_Y + 1)

typedef struct	s_vector
{
	int		x;
	int		y;
	int		z;
}				t_vector;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_cam
{
	int			zoom;
	t_vector	pos;
}				t_cam;

typedef struct	s_fdf
{
	t_point		p0;
	t_point		p1;
	t_cam		cam;
	t_vector	**map;
	void		*mlx;
	void		*win;
	int			sizex;
	int			sizey;
}				t_fdf;

t_fdf			*initialize_fdf(void);

int				check_size(t_fdf *fdf, int fd);

char			**read_map(t_fdf *fdf, int fd, int size);

void			make_map(t_fdf *fdf, char **cmap);
void			print_vector_map(t_fdf *fdf);
void			print_stats(t_fdf *fdf);

#endif
