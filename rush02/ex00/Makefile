# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahzerrou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 16:18:01 by ahzerrou          #+#    #+#              #
#    Updated: 2021/10/31 23:40:07 by omoudni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = rush-02
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
all:      ${NAME}
clean:
	rm -f $(OBJ)
fclean:   clean
	rm -f $(NAME)
re:       fclean all
