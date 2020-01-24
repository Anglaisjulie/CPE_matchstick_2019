/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** main.c
*/

#include "fonctions.h"

int main(int argc, char ** argv)
{
    int eof = 0;

    if (argc != 3)
        return (84);
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if ((argv[1][i] >= '0' && argv[1][i] <= '9')) {
        } else
            return (84);
    }
    for (int i = 0; argv[2][i] != '\0'; i++) {
        if ((argv[2][i] >= '0' && argv[2][i] <= '9')) {
        } else
            return (84);
    }
    eof = matchstick(argv, eof);
    if (eof == 84)
        return (84);
    if (eof == -1)
        return (0);
    return (0);
}