# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:43:34 by amoroziu          #+#    #+#              #
#    Updated: 2018/12/29 13:47:26 by amoroziu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libft/libftprintf.a

SRC = src/add_ant.c \
	  src/add_link.c \
	  src/algorithm.c \
	  src/algorithm2.c \
	  src/create_pathes.c \
	  src/delete.c \
	  src/delete_input_forks.c \
	  src/delete_output_forks.c \
	  src/find.c \
	  src/get_map.c \
	  src/get_room.c \
	  src/incorrect.c \
	  src/list_func.c \
	  src/main.c \
	  src/print_answer.c \
	  src/proceed_line.c \
	  src/queue_stuff.c \
	  src/remove.c \
	  src/work_with_map.c

FLAGC = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

all: $(LIB) $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(SRC)
	@gcc $(FLAGC) -c $(SRC)
	@gcc $(FLAGC) $(OBJ) $(LIB) -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ) 

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
