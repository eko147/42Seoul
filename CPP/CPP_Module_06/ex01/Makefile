SRCS    = main.cpp Serializer.cpp
OBJS	= ${SRCS:.cpp=.o}
CXX		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = serializer

all:		${NAME}

.cpp.o:		${SRCS}
			${CXX} ${CXXFLAGS} -c $^ -o ${^:.cpp=.o}

${NAME}:	${OBJS}
			$(CXX) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re%