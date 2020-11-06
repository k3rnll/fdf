/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:14:28 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 18:45:36 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../mlx/mlx.h"

void	update_img(t_fdf *fdf)
{
	map_to_points(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, WHITE, "rt x: q-w");
	mlx_string_put(fdf->mlx, fdf->win, 0, 16, WHITE, "rt y: a-s");
	mlx_string_put(fdf->mlx, fdf->win, 0, 32, WHITE, "rt z: z-x");
	mlx_string_put(fdf->mlx, fdf->win, 0, 48, WHITE, "zoom: d-c");
	mlx_string_put(fdf->mlx, fdf->win, 0, 64, WHITE,
			fdf->render->iso ? "proj: i-o : iso" : "proj: i-o : parallel");
	mlx_string_put(fdf->mlx, fdf->win, 0, 80, WHITE, "move: arrows");
}

void	map_zoom(t_fdf *fdf, int key)
{
	fdf->render->scale = key == KEY_D ?
			fdf->render->scale + 1 :
			fdf->render->scale - 1;
	update_img(fdf);
}

void	map_projection(t_fdf *fdf, int key)
{
	if (key == KEY_I)
	{
		fdf->render->iso = 1;
		fdf->render->ang_x = 0.0f;
		fdf->render->ang_y = 0.0f;
		fdf->render->ang_z = 0.0f;
	}
	else
	{
		fdf->render->iso = 0;
		fdf->render->ang_x = 0.5f;
		fdf->render->ang_y = 0.5f;
		fdf->render->ang_z = 0.5f;
	}
	update_img(fdf);
}
