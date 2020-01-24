/*
** EPITECH PROJECT, 2019
** match
** File description:
** intelligent_artificial.c
*/

#include "fonctions.h"

int ia(stick_t *stick)
{
    static int i = 0;
    int last = 0;
    if (stick->round == 2)
        i = stick->give_line - 1;
    while (stick->matches_per_line[i] <= 0)
        i--;
    last = (stick->matches_per_line[i] + stick->spaces[i]) - 1;
    stick->matches[i][last] = ' ';
    stick->matches_per_line[i]--;
    stick->total_matches--;
    my_printf("\nAI's turn...\nAI removed 1 match(es) from line %d\n", i + 1);
    if (stick->total_matches == 0)
        return (-6);
    return (0);
}

void print_ia(stick_t *stick)
{
    print_stars(stick);
    for (int i = 0; i != stick->give_line; i++) {
        my_putchar('*');
        my_putstr(stick->matches[i]);
        my_putchar('*');
        my_putchar('\n');
    }
    print_stars(stick);
}