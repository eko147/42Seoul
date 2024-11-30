# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunjiko <eunjiko@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 17:52:00 by eunjiko           #+#    #+#              #
#    Updated: 2023/01/15 15:27:20 by eunjiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= server client

NAME_SERVER = server

NAME_CLIENT = client

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= client.c server.c utils.c 

SERVER_SRC = server.c utils.c 
CLIENT_SRC = client.c utils.c 

OBJS	= ${SRCS:.c=.o}

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)


all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ) 
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJ)
	
$(NAME_CLIENT): $(CLIENT_OBJ) 
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJ)

.c.o:		${SRCS} 
	${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re