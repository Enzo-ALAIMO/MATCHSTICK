/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** main.c
*/

#include "matchstick.h"

int matchstick(char **board, int nb_lines, char **av)
{
    int total_matches = get_total_matches(board, nb_lines);
    if (player_turn(board, nb_lines, av) == 1) {
        my_putchar('\n');
        return (3);
    }
    if (total_matches == 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    ia_turn(board, nb_lines, av);
    total_matches = get_total_matches(board, nb_lines);
    if (total_matches == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int nb_lines;
    char **board;
    int end = 0;

    if (check_error(ac, av) == 1)
        return (84);
    nb_lines = my_getnbr(av[1]);
    board = init_board(nb_lines);
    display_board(board, (nb_lines * 2 + 1));
    while (1) {
        end = matchstick(board, nb_lines, av);
        if (end != 0 && end != 3)
            return (end);
        if (end == 3)
            return (0);
    }
    return (0);
}