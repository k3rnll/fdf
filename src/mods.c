/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:14:28 by k3                #+#    #+#             */
/*   Updated: 2020/11/04 17:21:35 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../mlx/mlx.h"

void 	update_img(t_fdf *fdf)
{
	map_to_points(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame->img_ptr, 0, 0);
}

void	change_map_height(t_fdf *fdf, int key)
{
	fdf->render->z_height = key == KEY_D ?
			fdf->render->z_height + 1 :
			fdf->render->z_height - 1;
	update_img(fdf);
}

void 	map_zoom(t_fdf *fdf, int key)
{
	fdf->render->scale = key == KEY_F ?
							fdf->render->scale + 1 :
							fdf->render->scale - 1;
	fdf->render->z_height = key == KEY_F ?
						 fdf->render->z_height + 1 :
						 fdf->render->z_height - 1;
	update_img(fdf);
}

void	map_projection(t_fdf *fdf, int key)
{
	fdf->render->iso = key == KEY_I ? 1 : 0;
	update_img(fdf);
}