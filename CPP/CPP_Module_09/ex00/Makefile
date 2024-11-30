SRCS    = main.cpp BitcoinExchange.cpp
OBJS	= ${SRCS:.cpp=.o}
CXX		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = btc

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