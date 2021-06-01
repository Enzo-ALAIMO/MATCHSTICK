##
## EPITECH PROJECT, 2020
## Projects
## File description:
## Makefile
##

SRC = 	./sources/main.c \
		./sources/util.c \
		./sources/util2.c \
		./sources/manage_sticks.c \
		./sources/check.c \
		./sources/display_turn.c \
		./sources/turns.c \
		./sources/get_input.c \

OBJ = $(SRC:.c=.o)

NAME = matchstick

CFLAGS +=  -Wall -W -Wextra

CPPFLAGS = -I./

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) matchstick.h -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
.PHONY: all clean fclean re
