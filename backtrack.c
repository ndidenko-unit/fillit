/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko/amnishen    <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:44:34 by amnishen          #+#    #+#             */
/*   Updated: 2017/12/16 15:36:10 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char		**put_tetri(t_tetri **t, int tn, char **map)
{
	map[t[tn]->y[0]][t[tn]->x[0]] = t[tn]->letter;
	map[t[tn]->y[0] + t[tn]->y[1]][t[tn]->x[0] + t[tn]->x[1]] = t[tn]->letter;
	map[t[tn]->y[0] + t[tn]->y[2]][t[tn]->x[0] + t[tn]->x[2]] = t[tn]->letter;
	map[t[tn]->y[0] + t[tn]->y[3]][t[tn]->x[0] + t[tn]->x[3]] = t[tn]->letter;
	return (map);
}

static	int			find_place(t_tetri **t, int tn, char **map, int n)
{
	if (t[tn]->y[0] + t[tn]->y[1] < n && t[tn]->x[0] + t[tn]->x[1] < n &&
		t[tn]->y[0] + t[tn]->y[2] < n && t[tn]->x[0] + t[tn]->x[2] < n &&
		t[tn]->y[0] + t[tn]->y[3] < n && t[tn]->x[0] + t[tn]->x[3] < n)
	{
		if (map[t[tn]->y[0]][t[tn]->x[0]] == '.' &&
			map[t[tn]->y[0] + t[tn]->y[1]][t[tn]->x[0] + t[tn]->x[1]] == '.' &&
			map[t[tn]->y[0] + t[tn]->y[2]][t[tn]->x[0] + t[tn]->x[2]] == '.' &&
			map[t[tn]->y[0] + t[tn]->y[3]][t[tn]->x[0] + t[tn]->x[3]] == '.')
		{
			map = put_tetri(t, tn, map);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

static	char		**remove_tetri(char **map, char a, int n)
{
	int		x;
	int		y;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			if (map[y][x] == a)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

int					backtrack(t_tetri **t, int tn, char **map, int n)
{
	if (t[tn] == NULL)
		return (1);
	t[tn]->y[0] = 0;
	while (t[tn]->y[0] < n)
	{
		t[tn]->x[0] = -1;
		while (++t[tn]->x[0] < n)
		{
			if (find_place(t, tn, map, n) == 1)
			{
				if (backtrack(t, tn + 1, map, n) == 1)
					return (1);
				map = remove_tetri(map, t[tn]->letter, n);
			}
		}
		t[tn]->y[0]++;
	}
	return (0);
}
