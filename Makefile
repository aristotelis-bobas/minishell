# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/13 15:12:27 by abobas        #+#    #+#                  #
#    Updated: 2020/05/29 18:14:32 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 			minishell

SRC_DIR	=		./src/

HEADER 	= 		./src/includes/minishell.h

SRC = 			minishell.c \
				initialization.c \
				environment_1.c \
				environment_2.c \
				prompt.c \
				signals.c \
				reset.c \
				parse.c \
				parse_read.c \
				parse_split.c \
				parse_sanitize.c \
				parse_validate.c \
				parse_quotes.c \
				parse_pipe_1.c \
				parse_pipe_2.c \
				parse_pipe_3.c \
				parse_expand_1.c \
				parse_expand_2.c \
				parse_expand_3.c \
				parse_redirect.c \
				evaluate.c \
				execute.c \
				path.c \
				builtins_1.c \
				builtins_2.c \
				utilities_1.c \
				utilities_2.c \
				utilities_3.c \
				utilities_4.c \
				utilities_5.c \
				utilities_6.c \
				debug.c

SRC :=			$(SRC:%=$(SRC_DIR)%)

FLAGS = 		-Wall -Werror -Wextra

LIB_DIR	=		./libft

LIB =			$(LIB_DIR)/libft.a

ADD_LIB = 		-L $(LIB_DIR) -lft

all: $(NAME)

$(NAME): $(LIB) $(SRC) $(HEADER)
	gcc $(FLAGS) $(SRC) $(ADD_LIB) -o $(NAME)

%.a:
	$(MAKE) -C $(LIB_DIR)

run: $(NAME) clean
	./minishell

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME) $(LIB)

re:	fclean all
