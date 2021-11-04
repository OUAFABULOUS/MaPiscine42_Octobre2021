# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 14:51:52 by omoudni           #+#    #+#              #
#    Updated: 2021/11/04 16:29:17 by omoudni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_atoi.c\
			ft_calc.c\
			main.c\
			used_func.c\

SRCS	= $(addprefix ./, ${SRC})

OBJS	= ${SRCS:.c=.o}

NAME	= do-op 

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
