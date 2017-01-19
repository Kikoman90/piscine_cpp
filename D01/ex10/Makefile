NAME = cato9tails

SRC = main.cpp \

OBJ = main.o \

CLANG = clang++

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) $(FLAGS) -o $@ $^

main.o:main.cpp
	@$(CLANG) $(FLAGS) -c -o $@ $<

clean:
	@rm -f main.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
