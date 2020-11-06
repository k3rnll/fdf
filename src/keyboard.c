/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:02:08 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 11:36:45 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

int		press_key(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_Q || key == KEY_W)
		map_x(fdf, key);
	if (key == KEY_A || key == KEY_S)
		map_y(fdf, key);
	if (key == KEY_Z || key == KEY_X)
		map_z(fdf, key);
	if (key == KEY_D || key == KEY_C)
		map_zoom(fdf, key);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		map_move(fdf, key);
	if (key == KEY_I || key == KEY_O)
		map_projection(fdf, key);
	return (1);
}
