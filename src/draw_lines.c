/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_lines.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 22:34:44 by mvan-hou       #+#    #+#                */
/*   Updated: 2019/09/23 22:52:48 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham_high(t_fdf *fdf, t_point p0, t_point p1)
{
}

void	bresenham_low(t_fdf *fdf, t_point p0, t_point p1)
{
	int		p;
	id_t	yi;
	t_point	d;

	yi = 1;
	d.x = (p1.x - p0.x);
	d.y = (p1.y - p0.y);
	if (d.y < 0)
	{
		yi = -1;
		d.y = -d.y;
	}
	p = (2 * d.y) - d.y;
	while (p0.x != p1.x)
	{
		if (POINT_IS_IN_WINDOW)
			PIXEL_PUT;
		if (p > 0)
		{
			p0.y = p0.y + yi;
			p = p - 2 * d.x;
		}
		p0.x++;
		p = p + 2 * d.y;
	}
}

void	swap_coords(t_point *p0, t_point *p1)
{
	int temp;

	temp = p0->x;
	p0->x = p1->x;
	p1->x = p0->x;
	temp = p0->y;
	p0->y = p1->y;
	p1->y = temp;
}

void	draw_line(t_fdf *fdf, t_point p0, t_point p1)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
		{
			swap_coords(&p0, &p1);
			bresenham_low(fdf, p0, p1);
		}
		else
			bresenham_low(fdf, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
		{
			swap_coords(&p0, &p1);
			bresenham_high(fdf, p0, p1);
		}
		else
			bresenham_high(fdf, p0, p1);
	}
}
