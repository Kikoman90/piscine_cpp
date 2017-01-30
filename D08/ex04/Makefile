# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 14:28:20 by fsidler           #+#    #+#              #
#    Updated: 2017/01/30 19:40:03 by fsidler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calculator

CLANG = clang++

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp \
	  Calculator.cpp \
	  NumToken.cpp \
	  OpToken.cpp \
	  ParOpenToken.cpp \
	  ParCloseToken.cpp \
	  

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
