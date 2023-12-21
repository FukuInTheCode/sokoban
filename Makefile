##
## EPITECH PROJECT, 2023
## my_ls Makefile
## File description:
## Placeholder
##

NAME   = my_sokoban

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

LIBS = -lcurses

SRC	= my_sokoban.c \
		my_strlen.c \
		my_strcpy.c \
		my_strdup.c \
		handle_game.c \
		handle_end.c \
		handle_player.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
