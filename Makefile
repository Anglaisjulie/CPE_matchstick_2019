##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=	gcc -fdiagnostics-color


FILE_LIST =		src/main.c \
				src/matchstick.c \
				src/print_game.c \
				src/input_game.c \
				src/intelligent_artificial.c \
				src/count.c \
				src/eof.c \
				src/binary_stick.c \
				src/lib/my_putstr.c \
				src/lib/my_putchar.c \
				src/lib/my_atoi.c \
				src/lib/my_printf.c \
				src/lib/flags.c 	\
				src/lib/my_put_nbr.c \
				src/lib/my_strlen.c \
				src/lib/my_put_unsigned_nbr.c \
				src/lib/my_putnbr_base.c \


SRC		= 		$(FILE_LIST)

OBJ		=		$(SRC:.c=.o)

NAME 	= 		matchstick

CFLAGS  = -Wextra -Wall -I./include -g3

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f src/*.o
	rm -f src/lib/*.o

fclean: clean
	rm -f $(NAME)

re:		fclean all