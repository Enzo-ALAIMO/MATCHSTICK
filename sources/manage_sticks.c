/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

int get_matches_line(char **board, int line)
{
    int cpt = 0;

    for (int i = 0; board[line - 1][i]; i++)
        if (board[line - 1][i] == '|')
            cpt++;
    return (cpt);
}

int get_total_matches(char **board, int nb_lines)
{
    int boardX = nb_lines * 2 - 1;
    int boardY = nb_lines;
    int j = 0;
    int cpt = 0;

    for (int i = 0; i < boardY; i++) {
        for (j = 0; j < boardX; j++) {
                if (board[i][j] == '|')
                    cpt++;
            else
                continue;
        }
    }
    return (cpt);
}

char **remove_matches(char **board, int line, int matches, int nb_lines)
{
    int sticks = get_matches_line(board, line);
    int boardX = nb_lines * 2 - 1;
    int j = 0;
    int cpt = -1;

    for (j = 0; j < boardX; j++) {
        if (board[line - 1][j] == '|')
            cpt++;
        if (cpt >= sticks - matches)
            board[line - 1][j] = ' ';
        else
            continue;
    }
    return (board);
}