/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:43:06 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 09:35:58 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"
#include "../mlx/mlx.h"

void		put_pixel(t_fdf *fdf, int x, int y, unsigned color)
{
	size_t		pos;

	color = abs(x) >= W_WIDTH / 2 || abs(y) >= W_HEIGHT / 2 ? 0 : color;
	x = abs(x) >= W_WIDTH / 2 ? 0 : W_WIDTH / 2 + x;
	y = abs(y) >= W_HEIGHT / 2 ? 0 : W_HEIGHT / 2 + y;
	pos = abs((y) * fdf->frame->size) + ((x) * 4);
	fdf->frame->img_str[pos + 2] = (char)((color & 0xFF0000u) >> 16u);
	fdf->frame->img_str[pos + 1] = (char)((color & 0xFF00u) >> 8u);
	fdf->frame->img_str[pos + 0] = (char)(color & 0xFFu);
}

void		clear_frame(t_fdf *fdf)
{
	ft_bzero(fdf->frame->img_str, fdf->frame->size * W_HEIGHT);
}

t_image		*new_frame(t_fdf *fdf)
{
	t_image	*frame;

	if (!(frame = malloc(sizeof(t_image))))
		return (0);
	frame->img_ptr = mlx_new_image(fdf->mlx, W_WIDTH, W_HEIGHT);
	frame->bpp = 0;
	frame->size = 0;
	frame->endian = 0;
	frame->img_str = mlx_get_data_addr(frame->img_ptr,
			&(frame->bpp), &(frame->size), &(frame->endian));
	return (frame);
}
