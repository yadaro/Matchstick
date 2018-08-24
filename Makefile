##
## Makefile for Makefile in /home/Yadaro/CPE_2016_BSQ
##
## Made by Yadaro YUN
## Login   <Yadaro@epitech.net>
##
## Started on  Tue Dec 13 12:04:04 2016 Yadaro YUN
## Last update Sun Jun 11 16:54:43 2017 Yadaro YUN
##

CC	=	gcc

RM	=	rm -f

NAME	=	matchstick

SRC	=	src/main.c			\
		lib/my_putstr.c			\
		lib/my_atoi.c			\
		lib/my_puterror.c		\
		lib/my_put_nbr.c		\
		lib/my_str_to_wordtab.c		\
		lib/my_strlen.c			\
		lib/get_next_line.c		\
		lib/my_str_isnum.c		\
		lib/my_showtab.c		\
		src/put_pipe.c			\
		src/new_game.c			\
		src/error_message.c		\
		src/new_ai.c

CFLAGS	+=	-Iinclude -Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
