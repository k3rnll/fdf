/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:45:43 by k3                #+#    #+#             */
/*   Updated: 2020/11/05 09:38:50 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

void 	free_points(t_fdf *fdf)
{
	size_t 	i;
	size_t 	total;

	total = fdf->map->width * fdf->map->height;
	i = 0;
	while (i < total)
	{
		ft_bzero(fdf->render->points[i], sizeof(t_point));
		i++;
	}
//	free(fdf->render->points);
}

