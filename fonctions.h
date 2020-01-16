/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** fonctions.h
*/

#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct stick_s {
    int take_max;
    int lines;
    int last_line;
    int left;
    int right;
    char **matches;
    char *input_matches;
    char *input_line;
    int matches_line;
} stick_t;

//FONCTIONS PRINCIPAUX
int parsing_matchstick(char **);
int print_matches(stick_t *);
int binary(stick_t *);
void right_and_left(stick_t *, int);
void add_binary(stick_t *, int);
void print_stick(stick_t *, int);
int input_game(stick_t *);
int error_input_matches(stick_t *, size_t);
int error_input_line(stick_t *, size_t);
int count_matches(stick_t *, int);
int error_input_li(stick_t *);
int error_input_mat(stick_t *);



//MY_PRINTF
int my_printf(char *, ...);
void flags(va_list, char *, int);
int flags_char(va_list, int, char *);
int flags_b_p(va_list, int, char *);
int flags_int(va_list, int, char *);


//LIBMY
void my_putchar(char);
int my_putstr(char *);
int my_put_nbr(int);
int my_strlen(char const *);
int my_putnbr_base (int, char const *);
int my_put_unsigned_nbr(unsigned int);
int	my_atoi(char *);

#endif