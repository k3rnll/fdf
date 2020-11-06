/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:15:54 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 10:59:27 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"
#include "../mlx/mlx.h"

#include <fcntl.h>

t_point		**new_points(t_fdf *fdf)
{
	t_point	**points;
	int 	y;

	points = malloc(8 * fdf->map->height);
	y = 0;
	while (y < fdf->map->height)
	{
		points[y] = malloc(sizeof(t_point) * fdf->map->width);
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
	render->z_height = render->scale;
//	render->z_height = (W_HEIGHT / (fdf->map->height + fdf->map->height / 2) +1) /
//			(abs(fdf->map->z_max) + abs(fdf->map->z_min) + 1);
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
	if(!ft_strstr(av[1], ".fdf"))
		put_error("Error: no map file");
	fd = open(av[1], O_RDONLY);
	if (fd < 1 || !(map = read_map(fd)))
		put_error("Error: invalid map file");
	fdf = init_mlx();
	fdf->map = map;
	init_render(fdf);
	update_img(fdf);
	mlx_key_hook(fdf->win, press_key, fdf);
	mlx_loop(fdf->mlx);
	exit(0);
}
