/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:14:41 by amnishen          #+#    #+#             */
/*   Updated: 2017/12/14 14:40:40 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			prev_map_size(t_tetri **t_arr)
//определяем предварительный размер карты (ее стороны)
{
	int		n;
	int		res;
	int		num_blocks;

	n = 0;
	res = 2;
	while (t_arr[n] != NULL)
		n++;
	num_blocks = (n) * 4;
	while (res * res < num_blocks)
		res++;
	return (res);
}

char		**map_create(int map_size)
// создаем первую строку и копируем пока y не станет равен размеру карты
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (map_size + 1))))
		return (NULL);
	if (!(map[y] = ft_strnew((size_t)map_size)))
		return (NULL);
	while (x < map_size)
		map[y][x++] = '.';
	y++;
	while (y < map_size)
	{
		if (!(map[y] = ft_strdup(map[0])))
			return (NULL);
		y++;
	}
	map[y] = NULL;
	return (map);
}
