/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** yes
*/
#include "matchstick.h"

int game_input(stick_t *stickos)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    while (stickos->amount > 0) {
        my_printf("Your Turn:\n");
        stickos->whosplay = 2;
        if (get_line(buffer, bufsize, stickos) == -1)
            return (-1);
        if (get_matches(buffer, bufsize, stickos) == -1)
            return (-1);
        my_printf("Player removed %d match(es) ", stickos->matches);
        my_printf("from line %d\n", stickos->lines - 1);
        print_updated_board(stickos);
        if (stickos->amount == 0)
            return (0);
        stickos->whosplay = 1;
        find_factors(stickos);
    }
}

int check_turns(stick_t *stick)
{
    if (stick->whosplay == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    if (stick->whosplay == 2)
        my_printf("You lost, too bad...\n");
}

int main(int argc, char **argv)
{
    stick_t *stickos = malloc(sizeof(stick_t));

    if (argc != 3){
        my_put_error("You have to give two arguments one for stick line and ");
        my_put_error("one for the number of stick you can remove by move\n");
        return (84);
    }
    stickos->height = my_getnbr(argv[1]);
    stickos->map = making_game_board(stickos->height + 2);
    stickos->len = (((stickos->height - 1) * 2) - 1);
    stickos->limit = my_getnbr(argv[2]);
    stickos->amount = stickos->height * stickos->height;
    if (game_input(stickos) == -1) {
        my_putchar('\n');
        return (0);
    }
    check_turns(stickos);
    return (stickos->whosplay);
}