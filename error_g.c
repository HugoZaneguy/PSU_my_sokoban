/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** error_g
*/

#include "include/my.h"

int check_error(int ac)
{
    if (ac > 2 || ac < 2) {
        my_putstr("To many or to few arguments\n");
        return (84);
    }
    return (0);
}

int check_map(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '#' && str[i] != 'O' && str[i] != 'P' && str[i] != 'X'
            && str[i] != ' ' && str[i] != '\n') {
                my_putstr("Invalid map !\n");
                return (84);
        }
    }
    return (0);
}