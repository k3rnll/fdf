/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:59:57 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 15:06:59 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

void	put_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

int		dist(int a, int b)
{
	return (a < b ? b - a : a - b);
}

int		ft_numlen(long tmp)
{
	int	i;

	i = 0;
	if (tmp == 0)
		return (1);
	tmp = tmp < 0 ? tmp * -1 : tmp;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

int		ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (i);
}

int		smart_atoi(char *str)
{
	char	**arg;
	int		tmp;
	int		len;
	int		i;

	arg = ft_strsplit(str, ',');
	if (!(len = ft_isnumber(*arg)) && len > 11)
		put_error("Error: Wrong integer in the map");
	tmp = ft_atoi(*arg);
	if (len != ft_numlen(tmp) + (*str == '-' || *str == '+'))
		put_error("Error: Wrong integer in the map");
	if (*str != '-' && tmp < 0)
		put_error("Error: Wrong integer in the map");
	if (*str == '-' && tmp > 0)
		put_error("Error: Wrong integer in the map");
	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	return (tmp);
}
