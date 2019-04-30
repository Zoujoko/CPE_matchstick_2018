/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** yes
*/

#ifndef MATCHSTICK_H_
	#define MATCHSTICK_H_
#include "my.h"

typedef struct stick_s{
    char **map;
    int height;
    int len;
    int matches;
    int lines;
    int limit;
    int save;
    int amount;
    int **factors;
    int whosplay;
}              stick_t;

//updating game board
int print_updated_board(stick_t *stickos);
int matches_error_case(stick_t *stickos);
int line_error_case(stick_t *stickos, char **buffer);
void removing_matches(stick_t *stickos, int j);
int matches_nbr(stick_t *stickos, int j);
int check_letter(char **buffer);

//making game board
int adding_pipe(int i, int j, int len, int height);
char what_adding(int i, int j, int len , int height);
char **making_game_board(int height);
int game_input(stick_t *stickos);

//cleanning buffer
int get_line(char *buffer, size_t bufsize, stick_t *stickos);
int get_matches(char *buffer, size_t bufsize, stick_t *stickos);

//algorithm
int find_factors(stick_t *stick);
#endif /* !MATCHSTICK_H_ */
