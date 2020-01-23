/*
** EPITECH PROJECT, 2019
** match
** File description:
** input_game.c
*/

#include "fonctions.h"

int game_input(stick_t *stick, int eof)
{
    if (eof == -1)
        return (eof);
    if (eof != 84)
        my_putstr("\nYour turn:\n");
    eof = error_input_line(stick, eof);
    if (eof == -1)
        return (eof);
    if (eof == 84)
        eof = error_input_line(stick, eof);
    if (eof == 84)
        game_input(stick, eof);
    if (eof == -1)
        return (eof);
    return (0);
}

int error_input_line(stick_t *stick, int eof)
{
    int len_line = 0;
    size_t size_line = 0;

    my_putstr("Line: ");
    if (getline(&stick->input_line, &size_line, stdin) == -1)
        eof = -1;
    if (eof == -1)
        return (eof);
    len_line = my_strlen(stick->input_line);
    if (len_line == 1) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    if (check_number(stick, len_line) == 84)
        return (84);
    eof = error_input_li(stick, eof);
    return (condition_eof(eof));
}

int error_input_li(stick_t *stick, int eof)
{
    size_t size_matches = 0;

    if (my_atoi(stick->input_line) == 0) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    if (my_atoi(stick->input_line) > stick->give_line) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    } else {
        eof = 0;
        my_putstr("Matches: ");
        if (getline(&stick->input_matches, &size_matches, stdin) == -1)
            eof = -1;
        if (eof == -1)
            return (eof);
        if (error_input_matches(stick) == 84) {
            eof = error_input_line(stick, eof);
            return (condition_eof(eof));
        }
    }
    return (0);
}

int error_input_matches(stick_t *stick)
{
    int len_matches = 0;

    len_matches = my_strlen(stick->input_matches);
    if (len_matches == 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    }
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
    if (my_atoi(stick->input_matches) > stick->remove_max_matches) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
                                                stick->remove_max_matches);
        return (84);
    }
    if (my_atoi(stick->input_matches) >
                    stick->matches_per_line[my_atoi(stick->input_line) - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    }
    else
        my_printf("Player removed %d match(es) from line %d\n",
                    my_atoi(stick->input_matches), my_atoi(stick->input_line));
    return (0);
}
