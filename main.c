/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** main.c
*/

#include "fonctions.h"

int main(int argc, char ** argv)
{
    if (argc != 3)
        return (84);
    if (parsing_matchstick(argv) == 84)
        return (84);
    return (0);
}