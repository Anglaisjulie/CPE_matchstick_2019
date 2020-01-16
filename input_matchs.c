/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** input_matchs.c
*/

#include "fonctions.h"

int input_game(stick_t *stick)
{
    size_t size_line = 0;
    size_t size_matches = 0;

    if (error_input_line(stick, size_line) == 84)
        input_game(stick);
    if (error_input_matches(stick, size_matches) == 84)
        input_game(stick);
    return (0);
}

int error_input_matches(stick_t *stick, size_t size_matches)
{
    int len_matches = 0;

    my_putstr("Matches: ");
    if (getline(&stick->input_matches, &size_matches, stdin) == -1)
        return (84);
    len_matches = my_strlen(stick->input_matches);
    for (int i = 0; i != len_matches; i++) {
        if ((stick->input_matches[i] >= '0' && stick->input_matches[i] <= '9')
            || (stick->input_matches[i] == '\n')) {
        } else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    if (error_input_mat(stick) == 84)
        return (84);
    return (0);
}

int error_input_mat(stick_t *stick)
{
    if (my_atoi(stick->input_matches) == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    }
    if (my_atoi(stick->input_matches) > stick->take_max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
                                                stick->take_max);
        return (84);
    }
    if (my_atoi(stick->input_matches) >
                            count_matches(stick, my_atoi(stick->input_line))) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    }
    else
        my_printf("Player removed %d match(es) from line %d",
                    my_atoi(stick->input_matches), my_atoi(stick->input_line));
    return (0);
}

int error_input_line(stick_t *stick, size_t size_line)
{
    int len_line = 0;

    my_putstr("Line: ");
    if (getline(&stick->input_line, &size_line, stdin) == -1)
        return (84);
    len_line = my_strlen(stick->input_line);
    if (len_line == 1) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    for (int i = 0; i != len_line; i++) {
        if ((stick->input_line[i] >= '0' && stick->input_line[i] <= '9')
            || (stick->input_line[i] == '\n')) {
        } else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
    }
    if (error_input_li(stick) == 84)
        return (84);
    return (0);
}

int error_input_li(stick_t *stick)
{
    if (my_atoi(stick->input_line) == 0) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    if (my_atoi(stick->input_line) > stick->lines) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    return (0);
}