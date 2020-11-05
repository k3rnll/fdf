/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:10:13 by k3                #+#    #+#             */
/*   Updated: 2020/11/01 23:52:47 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/fdf.h"

t_fdf	*init_mlx(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W_WIDTH, W_HEIGHT, "fdf");
	fdf->frame = new_frame(fdf);
	return (fdf);
}
