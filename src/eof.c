/*
** EPITECH PROJECT, 2019
** match
** File description:
** eof.c
*/

#include "fonctions.h"

int condition_eof(int eof)
{
    if (eof == 84)
        return (84);
    if (eof == -1)
        return (eof);
    if (eof == 0)
        return (0);
    return (0);
}

int check_number(stick_t *stick, int len_line)
{
    for (int i = 0; i != len_line; i++) {
        if ((stick->input_line[i] >= '0' && stick->input_line[i] <= '9')
            || (stick->input_line[i] == '\n')) {
        } else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    return (0);
}