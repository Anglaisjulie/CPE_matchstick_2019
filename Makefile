##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


FILE_LIST =		print_matchstick.c \
				binary_stick.c \
				main.c \
				my_putstr.c \
				my_putchar.c \
				my_atoi.c \
				#input_matchs.c \


SRC		= 		$(FILE_LIST)

OBJ		=		$(SRC:.c=.o)

NAME 	= 		matchstick

CFLAGS  = -Wextra -Wall -I./include

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:		fclean all