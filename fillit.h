/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko/amnishen    <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:48:56 by amnishen          #+#    #+#             */
/*   Updated: 2017/12/10 02:19:26 by amnishen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUF_SIZE 546

typedef	struct	s_tetri
{
	int			*x;
	int			*y;
	char		letter;
}				t_tetri;

int				total_check(char *str);
t_tetri			**tetri_arr(char *str);
int				prev_map_size(t_tetri **t_arr);
char			**map_create(int map_size);
int				backtrack(t_tetri **t_arr, int t_num, char **map, int n);
void			print_map(char **map);
char			*ft_strdup(const char *s1);
char			*ft_strnew(size_t size);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			ft_strdel(char **as);
#endif
