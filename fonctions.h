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

typedef struct stick_s {
    int take_max;
    int lines;
    int last_line;
    int left;
    int right;
    char **matches;
} stick_t;

//FONCTIONS PRINCIPAUX
int parsing_matchstick(char **);
int print_matches(stick_t *);
int binary(stick_t *);
void right_and_left(stick_t *, int);
void add_binary(stick_t *, int);
void print_stick(stick_t *, int);

//LIB
int my_putstr(char const *);
void my_putchar(char);
int	my_atoi(char *);

#endif