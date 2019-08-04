# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jphilip- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 22:23:44 by jphilip-          #+#    #+#              #
#    Updated: 2019/04/07 17:35:11 by jphilip-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = print.c check.c read.c main.c
LIBDIR = libft

OBJ = $(SRC:.c=.o)

CC = gcc
FLAG = -Wall -Wextra -Werror
LIBFLAGS = -L $(LIBDIR) -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(FLAG) $(LIBFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
