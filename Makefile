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
SRC_DIR = ./src/
OBJ_DIR = ./obj/
NAME = libftprintf.a
HEADER_DIR = ./includes/
HEADER_FILE = ft_printf.h
HEADER = $(HEADER_DIR)$(HEADER_FILE)
CC = gcc -Wall -Werror -Wextra
SRC = $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_loop.c $(SRC_DIR)ft_manage.c $(SRC_DIR)ft_size.c $(SRC_DIR)ft_apply.c $(SRC_DIR)ft_error.c $(SRC_DIR)ft_manage_2.c $(SRC_DIR)ft_printf.c $(SRC_DIR)ft_utils.c $(SRC_DIR)ft_str_utils.c $(SRC_DIR)ft_add.c
OBJ = $(OBJ_DIR)ft_atoi.o $(OBJ_DIR)ft_loop.o $(OBJ_DIR)ft_manage.o $(OBJ_DIR)ft_size.o $(OBJ_DIR)ft_apply.o $(OBJ_DIR)ft_error.o $(OBJ_DIR)ft_manage_2.o $(OBJ_DIR)ft_printf.o $(OBJ_DIR)ft_utils.o $(OBJ_DIR)ft_str_utils.o $(OBJ_DIR)ft_add.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : all

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADER_DIR)
	$(CC) -I $(HEADER_DIR) -o $@ -c $<  

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean
