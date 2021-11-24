# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eesta <eesta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 06:21:30 by eesta             #+#    #+#              #
#    Updated: 2021/11/19 06:21:36 by eesta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_B	= philo_bonus

SRCS_B 	= main_bonus.c utils_bonus.c init_bonus.c routine_bonus.c print_bonus.c

OBJS_B	= ${SRCS_B:.c=.o}

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

%.o:%.c
					@$(CC) ${CFLAGS} -c $< -o $(<:.c=.o)

all:	${PROG_B}

${PROG_B}:	${OBJS_B}
					@$(CC) ${OBJS_B} -o ${PROG_B} -lpthread
					@echo "\n BONUS Compiled\n"
					
clean:
					@rm -f ${OBJS_B}

fclean: 	clean
					@rm -f ${PROG_B}

re:			fclean all

.PHONY: all clean fclean re