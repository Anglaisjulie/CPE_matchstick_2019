/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "fonctions.h"

int parsing_matchstick(char **argv)
{
    stick_t *stick = malloc(sizeof(stick_t));

    stick->lines = my_atoi(argv[1]);
    stick->take_max = my_atoi(argv[2]);
    stick->last_line = stick->lines * 2;
    if (stick->last_line != 0)
        stick->last_line -= 1;
    if (print_matches(stick) == 84)
        return (84);
    my_putstr("Your turn:\n");
    input_game(stick);
    return (0);
}

int print_matches(stick_t *stick)
{
    if (binary(stick) == 84)
        return (84);
    for (int i = 0; i != stick->last_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i != stick->lines; i++) {
        my_putchar('*');
        print_stick(stick, i);
        my_putstr("*\n");
    }
    for (int i = 0; i != stick->last_line + 2; i++)
        my_putchar('*');
    my_putchar('\n');
    return (0);
}

void print_stick(stick_t *stick, int i)
{
    for (int j = 0; j != stick->last_line; j++) {
        if (stick->matches[i][j] == '0')
            my_putchar(' ');
        if (stick->matches[i][j] == '1')
            my_putchar('|');
    }
}