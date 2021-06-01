/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

static int check_num(char **av, int i, int j)
{
    if (av[i][j] >= '0' && av[i][j] <= '9')
        return (0);
    else
        return (1);
}

int check_error(int ac, char **av)
{
    if (ac != 3)
        return (1);
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j]; j++) {
            if (check_num(av, i, j) == 0)
                continue;
            else
                return (1);
        }
    }
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (1);
    if (my_getnbr(av[2]) <= 0)
        return (1);
    return (0);
}

int check_player_line(int line, int nb_lines)
{
    if (line < 1 || line > nb_lines) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int check_player_matches(char **board, stick_t stick, int max_matches)
{
    int nb_matches = get_matches_line(board, stick.line);

    if (stick.matches > max_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max_matches);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (stick.matches < 0 ) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (stick.matches > nb_matches) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    if (stick.matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    return (0);
}