/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:48:00 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 15:56:17 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_line(t_point *p1, t_point *p0, t_fdf *fdf)
{
	int	dserr[6];
	int	p[3];

	p[0] = p0->x;
	p[1] = p0->y;
	p[2] = p0->z;
	dserr[0] = dist(p0->x, p1->x);
	dserr[1] = -dist(p0->y, p1->y);
	dserr[2] = (p0->x < p1->x) ? 1 : -1;
	dserr[3] = (p0->y < p1->y) ? 1 : -1;
	dserr[4] = dserr[0] + dserr[1];
	while (p[0] != p1->x || p[1] != p1->y)
	{
		put_pixel(fdf, p[0], p[1], p0->color);
		if ((dserr[5] = dserr[4] * 2) >= dserr[1])
		{
			dserr[4] += dserr[1];
			p[0] += dserr[2];
		}
		if (dserr[5] <= dserr[0])
		{
			dserr[4] += dserr[0];
			p[1] += dserr[3];
		}
	}
}

t_point	*get_point(t_fdf *fdf, int x, int y)
{
	return (fdf->render->points[y] + x);
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;

	clear_frame(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width && get_point(fdf, x, y)->x < W_WIDTH &&
				get_point(fdf, x, y)->y < W_HEIGHT)
		{
			if (x < fdf->map->width - 1)
				set_line(get_point(fdf, x, y),
						get_point(fdf, x + 1, y),
						fdf);
			if (y < fdf->map->height - 1)
				set_line(get_point(fdf, x, y),
						get_point(fdf, x, y + 1),
						fdf);
			x++;
		}
		y++;
	}
}
