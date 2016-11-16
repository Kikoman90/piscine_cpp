NAME = megaphone

CLANG = clang++

FLAG = -Wall -Wextra -Werror

OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(FLAG) -o $@ $^

megaphone.o: megaphone.cpp
	@$(CLANG) $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
