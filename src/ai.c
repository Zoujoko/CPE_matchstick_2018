/*
** EPITECH PROJECT, 2019
** ia
** File description:
** yes
*/

#include "matchstick.h"

void sum_factors(stick_t *stick)
{
    for (int i = 0; i != 2; i++) {
        for (int j = 0; j <= stick->height; j++)
            stick->factors[stick->height + 2][0] += stick->factors[j][0];
        for (int j = 0; j <= stick->height; j++)
            stick->factors[stick->height + 2][1] += stick->factors[j][1];
        for (int j = 0; j <= stick->height; j++)
            stick->factors[stick->height + 2][2] += stick->factors[j][2];
    }
    for (int i = 0; i != 3 ; i++)
        stick->factors[stick->height + 2][i] /= 2;
}

int test_save(stick_t *stick, int j)
{
    int save = matches_nbr(stick, j);

    stick->factors[j] = malloc(sizeof(int) * (3));
    while (save > 0) {
        if (save % 4 == 0 && save != 0 && stick->limit >= 4) {
            save -= 4;
            stick->factors[j][2] += 1;
        }
        if (save % 2 == 0 && save != 0) {
            save -= 2;
            stick->factors[j][1] += 1;
        }
        if (save % 2 == 1 && save != 0) {
            save -= 1;
            stick->factors[j][0] += 1;
        }
    }
}

int find_possible_lines(stick_t *stick)
{
    int i = 0;

    stick->lines = 0;
    for (; stick->map[i] != NULL; i++) {
        if (stick->matches <= matches_nbr(stick, i))
            stick->lines = i;
    }
    if (stick->lines != 0) {
    my_printf("AI removed %d match(es)", stick->matches);
    my_printf(" from line %d\n", stick->lines);
    removing_matches(stick, stick->lines);
    for (int k = 0; k != stick->height + 2; k++)
        my_printf("%s\n", stick->map[k]);
    my_putchar('\n');
    }
}

int win_test(stick_t *stick)
{
    int last = stick->height + 2;
    int empty = 0;

    if (stick->factors[last][0] == 1 && stick->factors[last][1] == 1
        && stick->factors[last][2] == 0)
        stick->matches = 2;
    for (int j = 0; stick->map[j] != NULL; j++)
        if (matches_nbr(stick, j) == 0)
            empty++;
        else
            stick->lines = j;
    if (empty == stick->height - 1 &&
        matches_nbr(stick, stick->lines) == stick->limit + 1)
            stick->matches = stick->limit;
}

int find_factors(stick_t *stick)
{
    int save = 0;

    my_printf("AI's turn...\n");
    stick->matches = stick->save;
    stick->factors = malloc(sizeof(int *) * (stick->height + 2));
    for (int j = 0; stick->map[j] != NULL; j++) {
        test_save(stick, j);
    }
    sum_factors(stick);
    win_test(stick);
    find_possible_lines(stick);
    if (stick->lines == 0) {
        while (stick->lines == 0) {
            stick->matches--;
            find_possible_lines(stick);
        }
    }
}
