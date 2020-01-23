/*
** EPITECH PROJECT, 2019
** match
** File description:
** print_game.c
*/

#include "fonctions.h"

int game_print(stick_t *stick)
{
    int spc = 0;
    int line_remove = 0;
    int remove = 0;
    int a = 0;

    if (stick->round > 1) {
        print_stars(stick);
        print_sticks(stick, spc, line_remove, remove);
        if (stick->total_matches == 0)
            return (0);
        print_stars(stick);
        a = ia(stick);
        print_ia(stick);
        if (a == -6)
            return (-6);
    } else {
        print_stars(stick);
        binary(stick);
        print_stars(stick);
    }
    return (0);
}

void print_sticks(stick_t *stick, int spc, int line_remove, int remove)
{
    spc = (stick->matches_per_line[my_atoi(stick->input_line) - 1]
                    + stick->spaces[my_atoi(stick->input_line) - 1]) - 1;
    for (int i = 0; i != my_atoi(stick->input_matches); i++)
        stick->matches[my_atoi(stick->input_line) - 1][(spc - i)] = ' ';
    line_remove = my_atoi(stick->input_line) - 1;
    remove = my_atoi(stick->input_matches);
    stick->matches_per_line[line_remove] -= remove;
    for (int i = 0; i != stick->give_line; i++) {
        my_putchar('*');
        my_putstr(stick->matches[i]);
        my_putchar('*');
        my_putchar('\n');
    }
}

void print_stars(stick_t *stick)
{
    for (int i = 0; i != stick->nb_matches_last_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
}