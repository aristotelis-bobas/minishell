# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/15 21:54:45 by abobas        #+#    #+#                  #
#    Updated: 2020/05/17 14:58:24 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = 		ft_printf.o \
			ft_readline.o \
			ft_readfile.o \
			ft_realloc.o \
			ft_putchar.o \
			ft_putnbr_base.o \
			ft_putstr.o \
			ft_strcmp.o \
			ft_strdup.o \
			ft_strlen.o \
			ft_strncmp.o \
			ft_substr.o \
			ft_strjoin.o \
			ft_strtrim.o \
			vector_add.o \
			vector_delete.o \
			vector_free.o \
			vector_get.o \
			vector_init.o \
			vector_resize.o \
			vector_search.o \
			vector_set.o \
			vector_total.o \
			vector_populate.o \
			vector_print.o \
			vector_debug.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all