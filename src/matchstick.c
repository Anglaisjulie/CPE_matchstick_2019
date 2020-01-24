/*
** EPITECH PROJECT, 2019
** match
** File description:
** matchstick.c
*/

#include "fonctions.h"

int matchstick(char **argv, int eof)
{
    stick_t *stick;

    stick = malloc(sizeof(stick_t));
    if (stick == NULL)
        return (84);
    stick->give_line = my_atoi(argv[1]);
    if (stick->give_line < 2)
        return (84);
    stick->remove_max_matches = my_atoi(argv[2]);
    pyramid(stick);
    stick->nb_matches_last_line = (stick->give_line * 2) - 1;
    matches_lines(stick);
    eof = game_loop(stick, eof);
    if (eof == -1)
        return (eof);
    return (0);
}

int pyramid(stick_t *stick)
{
    stick->matches_per_line = malloc(sizeof(int) * stick->give_line);
    if (stick->matches_per_line == NULL)
        return (84);
    stick->spaces = malloc(sizeof(int) * stick->give_line);
    if (stick->spaces == NULL)
        return (84);
    return (0);
}

void matches_lines(stick_t *stick)
{
    int stock = 1;
    int a = stick->nb_matches_last_line / 2;

    for (int i = 0; i != stick->give_line; i++) {
        stick->matches_per_line[i] = stock;
        stick->total_matches += stock;
        stock += 2;
        stick->spaces[i] = a;
        a--;
    }
}

int game_loop(stick_t *stick, int eof)
{
    int a = 0;

    stick->round = 0;
    while (stick->total_matches != 0) {
        stick->round++;
        a = game_print(stick);
        if (a == -6) {
            my_printf("I lost... snif... but I'll get you next time!!");
            return (0);
        }
        if (stick->total_matches >= 0)
            eof = game_input(stick, eof);
        if (eof == -1)
            return (eof);
        stick->total_matches -= my_atoi(stick->input_matches);
    }
    print_lose(stick);
    my_printf("You lost, too bad...");
    return (0);
}