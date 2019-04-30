/*
** EPITECH PROJECT, 2019
** print game boar
** File description:
** yes
*/
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "matchstick.h"

int adding_pipe(int i, int j, int len, int height)
{
    int middle = len / 2;

    if (j >= 1 && j <= height - 1)
        if (i <= middle + (j - 1) && i >= middle - (j - 1))
            return (1);
    return (0);
}

char what_adding(int i, int j, int len, int height)
{
    if (j == 0 || j == height - 1 || i == 0 || i == len - 1)
        return ('*');
    else if (adding_pipe(i, j, len, height) == 1)
        return ('|');
    else
        return (' ');
}

char **making_game_board(int height)
{
    char **map = malloc(sizeof(char *) * (height + 1));
    int i = 0;
    int j = 0;
    int len = (((height - 1) * 2) - 1);

    map[0] = malloc(sizeof(char) * (len + 1) + 2);
    map[height + 1] = NULL;
    while (j != height) {
        while (i != len) {
            map[j][i] = what_adding(i, j, len, height);
            i++;
        }
        map[j][i] = '\0';
        my_printf("%s\n", map[j]);
        i = 0;
        j++;
        map[j] = malloc(sizeof(char) * (len + 1 + 2) );
    }
    my_putchar('\n');
    return (map);
}