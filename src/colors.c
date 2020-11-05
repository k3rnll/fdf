/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 07:44:24 by k3                #+#    #+#             */
/*   Updated: 2020/11/05 07:56:23 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned 	get_color(t_fdf *fdf, unsigned z)
{
	int		c_range;
	float 	step;

	if (fdf->map->z_max < 0 && fdf->map->z_min < 0)
		c_range = abs(fdf->map->z_max) - abs(fdf->map->z_min);
	else
		c_range = abs(fdf->map->z_max) + abs(fdf->map->z_min);
	step = 16.0f / (float)c_range;
	z = (int)((float)z * step);
	return (0xFF0000u >> z);
}
