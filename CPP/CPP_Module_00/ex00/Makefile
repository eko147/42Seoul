SRCS    = megaphone.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = megaphone

all:		${NAME}

.cpp.o:		${SRCS}
			${CC} ${CPPFLAGS} -c $^ -o ${^:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re