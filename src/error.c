/*
** EPITECH PROJECT, 2019
** erro
** File description:
** yes
*/

#include "matchstick.h"

int matches_error_case(stick_t *stickos)
{
    if (stickos->matches <= 0) {
        my_printf("Error: you have to remove atleast one match\n");
        return (1);
    }
    if (stickos->matches > stickos->limit) {
        my_printf("Error: you cannot remove more than ");
        my_put_nbr(stickos->limit);
        my_printf(" matches per turn\n");
        return (1);
    }
    if (stickos->matches > matches_nbr(stickos, stickos->lines - 1)) {
        my_printf("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int line_error_case(stick_t *stickos, char **buffer)
{
    if (stickos->lines <= 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (stickos->lines < 1 || stickos->lines > stickos->height + 2) {
        my_printf("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}