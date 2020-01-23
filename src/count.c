/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** count.c
*/

#include "fonctions.h"

int count_matches(stick_t *stick, int i)
{
    for (int j = 0; j != stick->nb_matches_last_line + 1; j++) {
        if (stick->matches[i - 1][j] == 1) {
            stick->matches_line++;
        }
    }
    return (stick->matches_line);
}

void print_lose(stick_t *stick)
{
    print_stars(stick);
    for (int i = 0; i != stick->give_line; i++) {
        my_putchar('*');
        for (int j = 0; j != stick->nb_matches_last_line; j++)
            stick->matches[i][j] = ' ';
        my_putstr(stick->matches[i]);
        my_putchar('*');
        my_putchar('\n');
    }
    print_stars(stick);
}