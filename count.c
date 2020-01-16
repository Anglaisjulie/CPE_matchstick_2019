/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** count.c
*/

#include "fonctions.h"

int count_matches(stick_t *stick, int i)
{
    for (int j = 0; j != stick->last_line + 1; j++) {
        if (stick->matches[i - 1][j] == '1') {
            stick->matches_line++;
        }
    }
    return (stick->matches_line);
}