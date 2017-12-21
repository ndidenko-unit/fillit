NAME = fillit
CFLAGS = -Wall -Werror -Wextra
FILES = backtrack.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strnew.c \
		main.c \
		map_set.c \
		tetri_set.c \
		valid_check.c 
OBJ = *.o
HEAD =  -c -I fillit.h

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(HEAD) $(FILES)
	gcc -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
