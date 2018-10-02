NAME = phonebook

CLANG = clang++

FLAG = -Wall -Wextra -Werror

SRC = Contact.cpp \
	  main.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(FLAG) -o $@ $^

%.o:%.cpp
	@$(CLANG) $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re