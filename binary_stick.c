/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** binary_stick.c
*/

#include "fonctions.h"

int binary(stick_t *stick)
{
    stick->left = stick->last_line / 2;
    stick->right = stick->last_line / 2 + 1;

    stick->matches = malloc(sizeof(char *) * (stick->lines + 1));
    if (stick->matches == NULL)
        return (84);
    for (int i = 0; i != stick->last_line; i++) {
        stick->matches[i] = malloc(sizeof(char) * (stick->last_line + 1));
        if (stick->matches[i] == NULL)
            return (84);
        stick->matches[i][stick->last_line] = '\0';
    }
    stick->matches[stick->lines] = NULL;
    for (int i = 0; i != stick->lines; i++) {
        add_binary(stick, i);
        stick->left--;
        stick->right++;
    }
    return (0);
}

void right_and_left(stick_t *stick, int i)
{
    for (int a = stick->right; a != stick->last_line; a++) {
                stick->matches[i][a] = '0';
    }
    for (int b = stick->left - 1; b != -1; b--)
        stick->matches[i][b] = '0';
}

void add_binary(stick_t *stick, int i)
{
    for (int j = 0; j != stick->last_line; j++) {
            stick->matches[i][j] = '1';
            right_and_left(stick, i);
    }
}