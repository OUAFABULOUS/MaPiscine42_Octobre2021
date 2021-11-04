# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 22:33:51 by omoudni           #+#    #+#              #
#    Updated: 2021/11/03 14:49:47 by omoudni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = $(addprefix srcs/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o :
	$(CC) $(FLAGS) -o $@ -c $< -Iincludes/ 

${NAME} : ${OBJS}
		ar rcs ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
