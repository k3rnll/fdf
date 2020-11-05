/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:25:53 by k3                #+#    #+#             */
/*   Updated: 2020/11/04 17:45:03 by k3               ###   ########.fr       */
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
		y =  y - fdf->render->scale;
	else if (key == KEY_DOWN)
		y = y + fdf->render->scale;
	else if (key == KEY_LEFT)
		x = x - fdf->render->scale;
	else
		x = x + fdf->render->scale;
	fdf->render->pos_x = x;
	fdf->render->pos_y = y;

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame->img_ptr, x, y);
}
