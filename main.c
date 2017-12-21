/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko/amnishen    <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:23:47 by amnishen          #+#    #+#             */
/*   Updated: 2017/12/14 14:40:55 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_map(char **map)
{
	int		n;

	n = 0;
	while (map[n] != NULL)
	{
		ft_putstr(map[n]);
		ft_putchar('\n');
		n++;
	}
}

static	void	make_fillit(char *buf)
{
	char	**map;
	t_tetri **t_arr;
	int		n;

	t_arr = tetri_arr(buf); 
	n = prev_map_size(t_arr);
	map = map_create(n);
	while (backtrack(t_arr, 0, map, n) == 0)
	{
		ft_strdel(map);
		n++;
		map = map_create(n);
	}
	print_map(map);
	ft_strdel(map);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (total_check(buf) == 1)
	{
		make_fillit(buf);
		return (0);
	}
	else
		ft_putstr("error\n");
	return (0);
}
