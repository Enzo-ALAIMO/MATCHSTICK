/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

char **init_board(int nb_lines)
{
    int boardX = nb_lines * 2 - 1;
    int boardY = nb_lines;
    char **board = mem_alloc_2d_array_char(boardX, boardY);
    int j = 0;

    for (int i = 0; i < boardY; i++) {
        for (j = 0; j < boardX; j++) {
            if ((j >= boardX / 2 - 1 * i) && (j <= boardX / 2 + 1 * i))
                board[i][j] = '|';
            else
                board[i][j] = ' ';
        }
    }
    return (board);
}

int player_turn(char **board, int nb_lines, char **av)
{
    return (display_player(board, nb_lines, av));
}

void ia_turn(char **board, int nb_lines, char **av)
{
    int line = 0;
    int matches = 0;
    int nb_matches = 0;

    while (nb_matches == 0) {
        line = get_line_ia(nb_lines);
        nb_matches = get_matches_line(board, line);
    }
    matches = get_matches_ia(nb_matches, av);
    display_ia(board, line, matches, nb_lines);
}