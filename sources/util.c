/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** util.c
*/

#include "matchstick.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}

char **mem_alloc_2d_array_char(int y, int x)
{
    int i;
    char **p;

    if (!(p = malloc(sizeof(char *) * x + 1)))
        return (NULL);
    i = 0;
    while (i < x)
        if (!(p[i++] = malloc(y)))
            return (NULL);
    return (p);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long c = 0;
    int signe = 0;
    int modsigne = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            signe = signe + 1;
        i++;
    } while (str[i] >= '0' && str[i] <= '9') {
            c = c * 10 + (str[i] - 48);
            i++;
    }
    modsigne = signe % 2;
    if (modsigne == 1)
        c = c * -1;
    if (c / 10 < -2147483648 || c / 10  > 2147483647)
        return (0);
    return (c);
}