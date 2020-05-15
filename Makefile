# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/13 15:12:27 by abobas        #+#    #+#                  #
#    Updated: 2020/05/15 17:36:18 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell

MAN_OBJ = 	minishell.o \
			prompt.o \
			read_input.o \
			split_input.o \
			input_check.o \
			parse_input_1.o \
			parse_input_2.o \
			parse_input_3.o \
			list.o \
			execute.o \
			builtins.o \
			environment.o \
			clean.o \
			utilities_1.o \
			utilities_2.o \
			utilities_3.o \
			troubleshoot.o 
			#launch.c

BON_OBJ =	

ifdef WITH_BONUS
OBJ_FILES = $(MAN_OBJ) $(BON_OBJ)
else
OBJ_FILES = $(MAN_OBJ)
endif

FLAGS = -Wall -Werror -Wextra

HEADER = minishell.h

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER)
	gcc $(FLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

run: $(NAME)
	./minishell

bonus: 
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -rf $(MAN_OBJ) $(BON_OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all