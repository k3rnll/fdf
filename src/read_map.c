/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:38 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 17:53:54 by k3               ###   ########.fr       */
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
	close(fd);
	return (map->width && map->height ? map : NULL);
}
