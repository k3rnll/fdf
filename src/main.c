/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:15:54 by k3                #+#    #+#             */
/*   Updated: 2020/11/05 09:36:55 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"
#include "../mlx/mlx.h"

#include <fcntl.h>

t_point		**new_points(t_fdf *fdf)
{
	t_point	**points;
	int 	x;
	int 	y;

	points = malloc(8 *
					(fdf->map->height * fdf->map->width));
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			points[x + y * fdf->map->width] = malloc(sizeof(t_point));
			x++;
		}
		y++;
	}
	return (points);
}
void 	init_render(t_fdf *fdf)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	render->points = new_points(fdf);

	render->scale = W_WIDTH / (fdf->map->width + fdf->map->width / 2);
	render->pos_x = 0;
	render->pos_y = 0;
	render->iso = 1;
	render->ang_x = 0.5f;
	render->ang_y = 0.5f;
	render->ang_z = 0.5f;
	render->z_height = ((render->scale * fdf->map->height) +1) /
					   (abs(fdf->map->z_max) + abs(fdf->map->z_min) + 1);

//	render->z_height = (W_HEIGHT / (fdf->map->height + fdf->map->height / 2) +1) /
//			(abs(fdf->map->z_max) + abs(fdf->map->z_min) + 1);
//	render->z_height = (W_HEIGHT / 4) / (fdf->map->z_max) + abs(fdf->map->z_min);
	fdf->render = render;
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;
	int 	fd;

	char	*str;

	fdf = 0;
	str = *av;
	map = NULL;
	if (ac < 2)
		put_error("Usage : ./fdf <filename> [ case_size z_size ]");
	fd = open(av[1], O_RDONLY);
	if (fd < 1 || !(map = read_map(fd)))
		put_error("Error: invalid map file");
	fdf = init_mlx();
	fdf->map = map;
	init_render(fdf);
	map_to_points(fdf);
	draw_map(fdf);

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->frame->img_ptr, 0, 0);
	mlx_key_hook(fdf->win, press_key, fdf);
	mlx_loop(fdf->mlx);
	exit(0);
}
