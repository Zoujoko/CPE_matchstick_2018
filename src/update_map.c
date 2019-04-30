/*
** EPITECH PROJECT, 2019
** print updated board
** File description:
** yes
*/

#include "matchstick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int matches_nbr(stick_t *stickos, int j)
{
    int matches = 0;
    int i = 0;

    while (stickos->map[j][i] != '\0') {
        if (stickos->map[j][i] == '|') {
            matches++;
        }
        i++;
    }
    return (matches);
}

void removing_matches(stick_t *stikos, int j)
{
    int i = my_strlen(stikos->map[j]);

    stikos->save = stikos->matches;
    while (stikos->matches != 0) {
        if (stikos->map[j][i] == '|') {
            stikos->map[j][i] = ' ';
            stikos->matches--;
            stikos->amount--;
        }
        i--;
    }
}

int print_updated_board(stick_t *stickos)
{
    int j = stickos->lines - 1;
    int k = 0;

    removing_matches(stickos, j);
    while (k != stickos->height + 2) {
        my_printf("%s\n", stickos->map[k]);
        k++;
    }
    my_putchar('\n');
    return (0);
}

int get_line(char *buffer, size_t bufsize, stick_t *stickos)
{
    my_printf("Line: ");
    if (getline(&buffer, &bufsize, stdin) == - 1)
        return (-1);
    stickos->lines = my_getnbr(buffer) + 1;
    while (line_error_case(stickos, &buffer)) {
        my_printf("Line: ");
        if (getline(&buffer, &bufsize, stdin) == - 1)
            return (-1);
        stickos->lines = my_getnbr(buffer) + 1;
    }
}

int get_matches(char *buffer, size_t bufsize, stick_t *stickos)
{
    my_printf("Matches: ");
    if (getline(&buffer, &bufsize, stdin) == - 1)
        return (-1);
    stickos->matches = my_getnbr(buffer);
    while (matches_error_case(stickos) != 0) {
        if (get_line(buffer, 
        bufsize, stickos) == -1)
            return (-1);
        my_printf("Matches: ");
        if (getline(&buffer, &bufsize, stdin) == - 1)
            return (-1);
        stickos->matches = my_getnbr(buffer);
    }
}
