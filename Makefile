##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=	gcc -fdiagnostics-color

FILE_LIST =		print_matchstick.c \
				binary_stick.c \
				main.c \
				my_putstr.c \
				my_putchar.c \
				my_atoi.c \
				count.c \
				input_matchs.c \
				my_printf.c \
				flags.c 	\
				my_put_nbr.c \
				my_strlen.c \
				my_put_unsigned_nbr.c \
				my_putnbr_base.c \


SRC		= 		$(FILE_LIST)

OBJ		=		$(SRC:.c=.o)

NAME 	= 		matchstick

CFLAGS  = -Wextra -Wall -I./include -g3

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:		fclean all