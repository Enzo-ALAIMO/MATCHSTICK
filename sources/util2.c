/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

static int m_gestion(long number)
{
    int tmp = 0;

    if (number >= 10) {
        tmp = number % 10;
        number = (number - tmp) / 10;
        m_gestion(number);
        my_putchar(tmp + '0');
    } else if (number < 10)
        my_putchar(number + '0');
    return (0);
}

int my_put_nbr(int nb)
{
    long number = nb;

    if (nb < 0) {
        my_putchar('-');
        number = number * -1;
        m_gestion(number);
    } else
        m_gestion(number);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
            i = i + 1;
        else
            return (0);
    }
    return (1);
}