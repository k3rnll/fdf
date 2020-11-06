/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:38 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 14:52:03 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

t_map		*close_fd_err(int fd)
{
	close(fd);
	return (NULL);
}

int			count_words(char *s, char c)
{
	int	i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

void		minmax_z(t_map *map)
{
	int	x;
	int	y;

	map->z_max = 0;
	map->z_min = 24222222;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->coords[y * map->width + x]->z > map->z_max)
				map->z_max = map->coords[y * map->width + x]->z;
			if (map->coords[y * map->width + x]->z < map->z_min)
				map->z_min = map->coords[y * map->width + x]->z;
			x++;
		}
		y++;
	}
}

t_map		*read_map(int fd)
{
	t_map	*map;
	char	*line;

	if (!(map = malloc(sizeof(t_map))))
		return (close_fd_err(fd));
	map->height = 0;
	map->width = 0;
	while (get_next_line(fd, &line))
	{
		if (map->width == 0)
			map->width = count_words(line, ' ');
		if (map->width != count_words(line, ' '))
		{
			free(line);
			return (close_fd_err(fd));
		}
		map->height += 1;
		str_to_coord(map, line);
		free(line);
	}
	minmax_z(map);
	close(fd);
	return (map);
}
