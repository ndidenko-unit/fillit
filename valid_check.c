/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnishen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:45:21 by amnishen          #+#    #+#             */
/*   Updated: 2017/12/02 13:16:07 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//проверяет на невалидные символы + размер массива
static	int		symbol_check(char *str)
{
	int		n;
	int		res;

	res = 0;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] != '#' && str[n] != '.' && str[n] != '\n')
			return (0);
		n++;
		if (str[n] == '#')
			res++; 
	}
	if (n <= 545 && res > 0)
		return (1);
	return (0);
}

static	int		size_check(char *str, int n)
{
	int		count_x;
	int		count_y;

	while (str[n] != '\0')
	{
		count_y = 0;
		//проверка на кол-во строк в блоке
		while (count_y++ != 4)
		{
			count_x = 0;
			//проверка на кол-во символов в строке
			while (count_x++ != 4)
			{
				if (str[n] != '.' && str[n] != '#') // убераем?
					return (0);
				n++;
			}
			if (str[n++] != '\n')
				return (0);
		}
		// проверка на пустую строку после блока
		if (str[n] == '\n' && str[n] != '\0')
			n++;
		else if (str[n] != '\0' && str[n] != '\n')
			return (0);
	}
	return (1);
}

static	int		chains_num(char *str, int start)
// проверка на количество # в тетрамине и возвращает кол-во связей
{
	int		n;
	int		res;
	int		count;

	count = 0;
	n = start - 1;
	res = 0;
	while (++n < start + 20)
	{
		if (str[n] == '#')
		{
			count++;
			if (str[n - 1] == '#')
				res++;
			if (str[n + 1] == '#')
				res++;
			if (str[n - 5] == '#' && n - 5 >= start)
				res++;
			if (str[n + 5] == '#' && n + 5 < start + 20)
				res++;
		}
	}
	if (count == 4)
		return (res);
	return (0);
}

static	int		tetri_check(char *str)
// если кол-во связей 6 или 8, переход к след блоку
{
	int		n;
	int		res;

	res = 0;
	n = -1;
	while (str[++n] != '\0')
	{
		if (chains_num(str, n) != 6 && chains_num(str, n) != 8)
			return (0);
		n = n + 20;
		if (str[n] == '\0')
			break ;
	}
	return (1);
}

int				total_check(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
		n++;
	if (symbol_check(str) == 1 && size_check(str, 0) == 1 &&
		tetri_check(str) == 1)
		return (1);
	else
		return (0);
}
