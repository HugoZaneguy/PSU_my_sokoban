/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** help
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int help(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("USAGE\n\t./my_sokoban map\n");
            my_putstr("DESCRIPTION\n");
            my_putstr("\tmap file representing the warehouse map, containing");
            my_putstr("'#' for walls\n");
            my_putstr("\t   'P' for the player, 'X' for boxes and 'O' ");
            my_putstr("for storage locations.\n");
        }
    }
    return (0);
}