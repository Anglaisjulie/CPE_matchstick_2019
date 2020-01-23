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
    int *matches_per_line;
    int *spaces;
    int give_line;
    int remove_max_matches;
    int nb_matches_last_line;
    int total_matches;
    int matches_line;
    int left;
    int right;
    int round;
    char *input_line;
    char *input_matches;
    char **matches;
} stick_t;

//FONCTIONS PRINCIPAUX
int matchstick(char **, int);
void matches_lines(stick_t *);
int game_print(stick_t *);
void right_and_left(stick_t *, int);
void add_binary(stick_t *, int);
int binary(stick_t *);
void print_stars(stick_t *);
int game_loop(stick_t *, int);
int game_input(stick_t *, int);
int error_input_matches(stick_t *);
int error_input_line(stick_t *, int);
int error_input_li(stick_t *, int);
int error_input_mat(stick_t *);
int count_matches(stick_t *, int);
int pyramid(stick_t *);
int condition_eof(int);
int ia(stick_t *);
void print_ia(stick_t *);
void print_lose(stick_t *);
void print_sticks(stick_t *, int, int, int);
int check_number(stick_t *, int);

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