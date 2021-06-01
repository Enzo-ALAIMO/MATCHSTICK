/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>

typedef struct stick_s {
    int line;
    int matches;
} stick_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *str);
char **mem_alloc_2d_array_char(int y, int x);
int get_matches_line(char **board, int line);
int get_total_matches(char **board, int nb_lines);
char **remove_matches(char **board, int line, int matches, int nb_lines);
char **init_board(int nb_lines);
int check_error(int ac, char **av);
int get_input_player(void);
int get_line_ia(int nb_lines);
int get_matches_ia(int nb_matches, char **av);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void display_board(char **board, int x);
int player_turn(char **board, int nb_lines, char **av);
void ia_turn(char **board, int nb_lines, char **av);
int display_player(char **board, int nb_lines, char **av);
void display_ia(char **board, int line, int matches, int nb_lines);
int check_player_line(int line, int nb_lines);
int check_player_matches(char **board, stick_t stick, int max_matches);
int my_str_isnum(char const *str);

#endif