/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

int get_input_player(void)
{
    char *line = NULL;
    size_t len = 10;
    int nb;

    if (getline(&line, &len, stdin) < 0)
        return (-98);
    if (my_str_isnum(line) == 0)
        return (-97);
    nb = my_getnbr(line);
    return (nb);
}

int get_line_ia(int nb_lines)
{
    int line = 0;

    srand(time(NULL));
    while (1) {
        line = rand() % (nb_lines + 1);
        if (line > 0)
            break;
    }
    return (line);
}

int get_matches_ia(int nb_matches, char **av)
{
    int matches = 0;

    srand(time(NULL));
    while (1) {
        matches = rand() % (nb_matches + 1);
        if (matches > 0 && matches <= my_getnbr(av[2]))
            break;
    }
    return (matches);
}