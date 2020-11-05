/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:48:00 by k3                #+#    #+#             */
/*   Updated: 2020/11/05 08:30:00 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_abs(int a, int b)
{
	return (a < b ? b - a : a - b);
}

void	set_line(t_point *p1, t_point *p0, t_fdf *fdf)
{
	int		dserr[6];
	int		p[3];

	p[0] = p0->x;
	p[1] = p0->y;
	p[2] = p0->z;
	dserr[0] = ft_abs(p0->x, p1->x);
	dserr[2] = (p0->x < p1->x) ? 1 : -1;
	dserr[1] = -ft_abs(p0->y, p1->y);
	dserr[3] = (p0->y < p1->y) ? 1 : -1;
	dserr[4] = dserr[0] + dserr[1];
	while (p[0] != p1->x || p[1] != p1->y)
	{
		put_pixel(fdf, p[0], p[1], 0xFFFFu);
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

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;

	clear_frame(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				set_line(get_point(x, y, fdf), get_point(x + 1, y, fdf), fdf);
			if (y != fdf->map->height - 1)
				set_line(get_point(x, y, fdf), get_point(x, y + 1, fdf), fdf);
			x++;
		}
		y++;
	}
}