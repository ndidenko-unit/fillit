/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko/amnishen    <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:09:22 by amnishen          #+#    #+#             */
/*   Updated: 2017/12/16 15:36:20 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_tetri		*new_tetri(char *str, int start, char letter)
{
	t_tetri		*tetri;
	int			n;
	int			flag;

	tetri = (t_tetri*)malloc(sizeof(t_tetri));
	tetri->x = (int*)malloc(sizeof(int) * 4);
	tetri->y = (int*)malloc(sizeof(int) * 4);
	n = start - 1;
	flag = 0;
	while (++n < start + 20)
	{
		if (str[n] == '#' && flag == 0)
		{
			tetri->x[0] = (n - start) % 5;
			tetri->y[0] = (n - start) / 5;
			flag = 1;
		}
		else if (str[n] == '#' && flag > 0)
		{
			tetri->x[flag] = (n - start) % 5 - tetri->x[0];
			tetri->y[flag++] = (n - start) / 5 - tetri->y[0];
		}
	}
	tetri->letter = letter;
	return (tetri);
}

static	int			tetri_num(char *str)
{
	int			n;
	int			res;

	n = 0;
	res = 0;
	while (str[n++] != '\0')
	{
		if (str[n] == '\n')
			res++;
	}
	return (++res / 5);
}

t_tetri				**tetri_arr(char *str)
{
	int			a;
	int			num;
	int			n;
	char		letter;
	t_tetri		**t_arr;

	num = 0;
	if (!(t_arr = (t_tetri**)malloc(sizeof(t_tetri*) * (tetri_num(str) + 1))))
		return (NULL);
	letter = 'A';
	n = 0;
	while (str[n] != '\0')
	{
		if (!(t_arr[num++] = new_tetri(str, n, letter++)))
			return (NULL);
		n = n + 20;
		if (str[n] != '\0')
			n++;
	}
	t_arr[num] = NULL;
	a = 0;
	return (t_arr);
}
