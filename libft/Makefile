# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 13:02:27 by amoroziu          #+#    #+#              #
#    Updated: 2018/12/14 16:41:23 by amoroziu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_bzero.c \
		ft_memset.c \
		ft_memcpy.c\
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_putchar.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isspace.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstpushback.c \
		ft_printf.c \
		ft_doubleitoa.c \
		ft_freejoin.c \
		get_next_line.c \
		ft_arr_size.c \
		conversation.c \
		flag.c \
		arrdel.c \
		format.c \
		length.c \
		mfw.c \
		check_if_null.c \
		print_sdecimal.c \
		print_udecimal.c \
		print_uoctal.c \
		print_uhex.c \
		print_char.c \
		print_string.c \
		print_pointer.c \
		print_float.c \
		print_percent.c

FLAGC = -Wall -Wextra -Werror

.PHONY: all clean fclean re

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAGC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: re clean
	@gcc test.c libftprintf.a
	@./a.out
