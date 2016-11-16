# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsidler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 19:04:56 by fsidler           #+#    #+#              #
#    Updated: 2016/11/07 19:19:34 by fsidler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CLANG = clang++

FLAG = -Wall -Wextra -Werror

SRC = replace.cpp

OBJ = replace.o

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(FLAG) -o $@ $^

replace.o: replace.cpp
	@$(CLANG) $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
