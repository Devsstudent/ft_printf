# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odessein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 15:47:29 by odessein          #+#    #+#              #
#    Updated: 2022/05/23 19:00:42 by odessein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = gcc -Wall -Werror -Wextra
SRC = ft_atoi.c ft_loop.c ft_manage.c ft_size.c ft_apply.c ft_error.c ft_manage_2.c ft_printf.c ft_utils.c ft_str_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean
