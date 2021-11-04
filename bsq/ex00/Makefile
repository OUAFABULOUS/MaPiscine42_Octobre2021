# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 14:51:52 by omoudni           #+#    #+#              #
#    Updated: 2021/11/03 22:27:49 by omoudni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_convert.c\
			ft_extract_inputs.c\
			ft_find.c\
			ft_open_store.c\
			ft_print.c\
			ft_split.c\
			ft_free.c\
			main.c\
			used_func.c\
			used_func_2.c

SRCS	= $(addprefix ./, ${SRC})

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

RM		= rm -f

CC		= gcc

FLAGS	= -Wall -Wextra -Werror 

.c.o :
		${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o} 

$(NAME) : ${OBJS}
		${CC} ${FLAGS} ${SRCS} -o ${NAME}

all:     ${NAME}

clean:
		${RM} ${OBJS}

fclean:   clean
		${RM} ${NAME}

re:       fclean all
