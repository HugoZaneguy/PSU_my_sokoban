##
## EPITECH PROJECT, 2019
## delivery
## File description:
## Makefile
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= ./help.c \
		  ./error_g.c \
		  ./lib/my/my_putstr.c \
		  ./lib/my/my_putchar.c \
		  ./lib/my/my_strlen.c \
		  ./my_sokoban.c \
		  ./game.c \
		  ./check.c \
	      ./main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re