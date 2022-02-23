# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 11:08:46 by oel-yous          #+#    #+#              #
#    Updated: 2022/02/23 14:26:13 by oel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

NAME = containers

SRCS = main.cpp

FLAGS =  -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME):	$(SRCS)
		$(CC) $(FLAGS) -o $(NAME) $(SRCS)
clean:
			@rm -rf *.o			
fclean: clean
			@rm -rf $(NAME)

re:		fclean all