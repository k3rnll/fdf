/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:51:07 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 14:53:17 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_x(t_fdf *fdf, int key)
{
	if (!fdf->render->iso)
	{
		fdf->render->ang_x = key == KEY_Q ?
			fdf->render->ang_x - 0.1f :
			fdf->render->ang_x + 0.1f;
		update_img(fdf);
	}
}

void	map_y(t_fdf *fdf, int key)
{
	if (!fdf->render->iso)
	{
		fdf->render->ang_y = key == KEY_A ?
			fdf->render->ang_y + 0.1f :
			fdf->render->ang_y - 0.1f;
		update_img(fdf);
	}
}

void	map_z(t_fdf *fdf, int key)
{
	if (!fdf->render->iso)
	{
		fdf->render->ang_z = key == KEY_Z ?
			fdf->render->ang_z - 0.1f :
			fdf->render->ang_z + 0.1f;
		update_img(fdf);
	}
}
