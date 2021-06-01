/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

void display_board(char **board, int x)
{
    for (int i = 0; i < x; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; board[i]; i++) {
        my_putchar('*');
        my_putstr(board[i]);
        my_putchar('*');
        my_putchar('\n');
    }
    for (int i = 0; i < x; i++)
        my_putchar('*');
    my_putchar('\n');
}

static void display_msg_player(int matches, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int display_player(char **board, int nb_lines, char **av)
{
    stick_t stick = {0};

    my_putstr("\nYour turn:\n");
    while (1) {
        my_putstr("Line: ");
        stick.line = get_input_player();
        if (stick.line == -97) {
            my_putstr("Error: invalid input (positive number expected)\n");
            continue;
        }
        if (stick.line == -98)
            return (1);
        if (check_player_line(stick.line, nb_lines) != 0)
            continue;
        my_putstr("Matches: ");
        stick.matches = get_input_player();
        printf("max_match before function = %d\n", my_getnbr(av[2]));
        if (check_player_matches(board, stick, my_getnbr(av[2]) != 0))
            continue;
        break;
    }
    display_msg_player(stick.matches, stick.line);
    remove_matches(board, stick.line, stick.matches, nb_lines);
    display_board(board, (nb_lines * 2 + 1));
    return (0);
}

void display_ia(char **board, int line, int matches, int nb_lines)
{
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    remove_matches(board, line, matches, nb_lines);
    display_board(board, (nb_lines * 2 + 1));
}