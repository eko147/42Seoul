SRCS	= ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
			printp.c printxu.c
				
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

all :		${NAME}

.c.o:		${SRCS} 
	${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re