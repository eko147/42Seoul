# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 17:15:46 by eunjiko           #+#    #+#              #
#    Updated: 2023/03/04 19:17:13 by eunjiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= push_swap.c ft_atoi.c ft_split.c ft_strjoin.c  ft_strlen.c \
			ft_strdup.c oper_s.c oper_p.c oper_r.c a_to_b.c b_to_a.c \
			operlist.c utills.c oper_rr.c hard_sort.c utills2.c
OBJS	= ${SRCS:.c=.o}


all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

norm:
			norminette ${SRCS}

.PHONY:		all clean fclean re norm
