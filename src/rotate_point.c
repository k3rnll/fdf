/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:54:20 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 15:54:20 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

void		rotate_x(t_point *p, double ang)
{
	int	y;
	int	z;

	y = p->y;
	z = p->z;
	p->y = (int)(y * cos(ang) + z * sin(ang));
	p->z = (int)(-y * sin(ang) + z * cos(ang));
}

void		rotate_y(t_point *p, double ang)
{
	int	x;
	int	z;

	x = p->x;
	z = p->z;
	p->x = (int)(x * cos(ang) + z * sin(ang));
	p->z = (int)(-x * sin(ang) + z * cos(ang));
}

void		rotate_z(t_point *p, double ang)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (int)(x * cos(ang) - y * sin(ang));
	p->y = (int)(x * sin(ang) + y * cos(ang));
}
