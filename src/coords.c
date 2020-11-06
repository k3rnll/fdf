/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:58:02 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 15:58:02 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

t_coord		*new_coord(char *str)
{
	t_coord	*new_coord;

	if (!(new_coord = malloc(sizeof(t_coord))))
		return (NULL);
	new_coord->z = smart_atoi(str);
	return (new_coord);
}

t_coord		**split_coords(t_map *map, t_coord **current)
{
	t_coord	**new;
	int		old_len;

	old_len = map->width * (map->height - 1);
	if (!(new = malloc(8 * (map->width * (map->height)))))
	{
		free(map->coords);
		free(current);
		put_error("Error: malloc");
	}
	ft_memcpy(new, map->coords, 8 * old_len);
	ft_memcpy(new + old_len, current, 8 * (map->width));
	free(map->coords);
	free(current);
	return (new);
}

int			str_to_coord(t_map *map, char *line)
{
	char		**arr;
	t_coord		**new_coords;
	int			i;

	if (!(arr = ft_strsplit(line, ' ')) ||
		!(new_coords = malloc(8 * map->width)))
		put_error("Error: malloc");
	i = 0;
	while (i < map->width)
	{
		new_coords[i] = new_coord(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	map->coords = map->height > 1 ? split_coords(map, new_coords) : new_coords;
	return (1);
}
