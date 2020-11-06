/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 07:57:12 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 10:58:14 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

void	iso(t_point *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (int)((prev_x - prev_y) * cos(3.1415926535 / 6));
	p->y = (int)(p->z + (prev_x + prev_y) * sin(3.1415926535 / 6));
}

void 		rotate_x(t_point *p, double ang)
{
	int	y;
	int	z;

	y = p->y;
	z = p->z;
	p->y = (int)(y * cos(ang) + z * sin(ang));
	p->z = (int)(-y * sin(ang) + z * cos(ang));
}

void 		rotate_y(t_point *p, double ang)
{
	int	x;
	int	z;

	x = p->x;
	z = p->z;
	p->x = (int)(x * cos(ang) + z * sin(ang));
	p->z = (int)(-x * sin(ang) + z * cos(ang));
}

void 		rotate_z(t_point *p, double ang)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (int)(x * cos(ang) - y * sin(ang));
	p->y = (int)(x * sin(ang) + y * cos(ang));
}

void		point_to_grid(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->render->scale;
	p->y *= fdf->render->scale;
	p->z = p->z / 2 * -(fdf->render->z_height);
	p->x -= fdf->map->width * fdf->render->scale / 2;
	p->y -= fdf->map->height * fdf->render->scale / 2;
	if (fdf->render->iso)
		iso(p);
	else
	{
		rotate_x(p, fdf->render->ang_x);
		rotate_y(p, fdf->render->ang_y);
		rotate_z(p, fdf->render->ang_z);
	}
	p->x += fdf->render->pos_x;
	p->y += fdf->render->pos_y;
}

t_point		*get_point(int x, int y, t_fdf *fdf)
{
	t_point *p;
	p = fdf->render->points[x + y * fdf->map->width];
	return (p);
}

void		new_point(t_fdf *fdf, int x, int y)
{
	t_point	*p;

	p = fdf->render->points[y] + x;
	p->x = x;
	p->y = y;
	p->z = fdf->map->coords[x + y * fdf->map->width]->z;
	p->color = WHITE;
	point_to_grid(p, fdf);
}

void	map_to_points(t_fdf *fdf)
{
//	t_point	**points;
	int 	x;
	int		y;

//	points = malloc(sizeof(t_point**) *
//					(fdf->map->height * fdf->map->width));
//	*(fdf->render->points) ? free_points(fdf) : 0;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			new_point(fdf, x, y);
			x++;
		}
		y++;
	}
//	fdf->render->points ? free_points(fdf) : 0;
//	fdf->render->points = points;
}