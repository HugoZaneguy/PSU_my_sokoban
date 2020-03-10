/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** check
*/

#include "include/my.h"

void reset(char **av, player_t *p)
{
    if (p->key == ' ') {
        char *map = fs_open_file(av[1]);
        p->tab = my_str_to_arr(map);
    }
}