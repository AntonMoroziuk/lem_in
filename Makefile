# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/29 14:28:47 by amoroziu          #+#    #+#              #
#    Updated: 2018/12/29 14:37:37 by amoroziu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

# srcs, path and obj

SRC_N			=	add_ant.c \
                    add_link.c \
					algorithm.c \
					algorithm2.c \
					create_pathes.c \
					delete.c \
					delete_input_forks.c \
					delete_output_forks.c \
					find.c \
					get_map.c \
					get_room.c \
					incorrect.c \
					list_func.c \
					main.c \
					print_answer.c \
					proceed_line.c \
					queue_stuff.c \
					remove.c \
					work_with_map.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), lem_in.h)

# libft

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ftprintf

# compiler

CC 				= gcc
CC_FLAGS 		= -g -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME)

obj:
	@mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	@$(CC) $(CC_FLAGS) $(INC_LIB) -I $(INC_P) -o $@ -c $<

$(ADD_LIB):
	@make -C $(LIB_P)

$(NAME): $(OBJ)
	@$(CC) $(LNK_LIB) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ_P)
	@make -C $(LIB_P) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIB_P) fclean

re: fclean all

.PHONY: all clean fclean re
