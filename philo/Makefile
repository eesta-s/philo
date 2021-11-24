# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eesta <eesta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 06:19:57 by eesta             #+#    #+#              #
#    Updated: 2021/11/19 06:20:16 by eesta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= philo

SRCS	= main.c time.c init.c doing.c print.c

OBJS 	= ${SRCS:.c=.o}

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

%.o:%.c		
					@$(CC) ${CFLAGS} -c $< -o $(<:.c=.o)

all:	${PROG}

${PROG}:	${OBJS}
					@$(CC) ${OBJS} -o ${PROG} -lpthread
					@echo "\n Philosophers Compiled\n"

clean:
					@rm -f ${OBJS}

fclean: 	clean
					@rm -f ${PROG}

re:			fclean all

.PHONY: all clean fclean re