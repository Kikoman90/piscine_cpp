# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 14:28:20 by fsidler           #+#    #+#              #
#    Updated: 2017/01/20 16:01:55 by fsidler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

CLANG = clang++

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(FLAGS) -o $@ $^

%.o:%.cpp
	@$(CLANG) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
