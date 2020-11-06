/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:25:53 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 09:39:37 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../mlx/mlx.h"

void 	map_move(t_fdf *fdf, int key)
{
	int x;
	int y;

	x = fdf->render->pos_x;
	y = fdf->render->pos_y;
	if (key == KEY_UP)
		y =  y - 20;
	else if (key == KEY_DOWN)
		y = y + 20;
	else if (key == KEY_LEFT)
		x = x - 20;
	else
		x = x + 20;
	fdf->render->pos_x = x;
	fdf->render->pos_y = y;

	update_img(fdf);
}
