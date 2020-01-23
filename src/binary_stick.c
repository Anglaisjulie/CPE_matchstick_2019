/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** binary_stick.c
*/

#include "fonctions.h"

int binary(stick_t *stick)
{
    stick->left = stick->nb_matches_last_line / 2;
    stick->right = stick->nb_matches_last_line / 2 + 1;

    stick->matches = malloc(sizeof(char *) * (stick->give_line + 1));
    if (stick->matches == NULL)
        return (84);
    for (int i = 0; i != stick->nb_matches_last_line; i++) {
        stick->matches[i] = malloc(sizeof(char) *
                                            (stick->nb_matches_last_line + 1));
        if (stick->matches[i] == NULL)
            return (84);
    }
    for (int i = 0; i != stick->give_line; i++)
        add_binary(stick, i);
    return (0);
}

void right_and_left(stick_t *stick, int i)
{
    for (int a = stick->right; a != stick->nb_matches_last_line; a++) {
                stick->matches[i][a] = ' ';
    }
    for (int b = stick->left - 1; b != -1; b--)
        stick->matches[i][b] = ' ';
}

void add_binary(stick_t *stick, int i)
{
    for (int j = 0; j != stick->nb_matches_last_line; j++) {
            stick->matches[i][j] = '|';
            right_and_left(stick, i);
    }
    stick->left--;
    stick->right++;
    my_putchar('*');
    my_putstr(stick->matches[i]);
    my_putchar('*');
    my_putchar('\n');
}