/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** game
*/

#include "include/my.h"

void mvup(player_t *p)
{
    if (p->tab[p->pos_y - 1][p->pos_x] != '#') {
        if (p->tab[p->pos_y - 1][p->pos_x] == 'X'
            && p->tab[p->pos_y - 2][p->pos_x] != '#'
            && p->tab[p->pos_y - 2][p->pos_x] != 'X') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y - 2][p->pos_x] = 'X';
            p->tab[p->pos_y - 1][p->pos_x] = 'P';
        } else if (p->tab[p->pos_y - 1][p->pos_x] != 'X'
            && p->buff[p->pos_y][p->pos_x] == 'O') {
            p->tab[p->pos_y - 1][p->pos_x] = 'P';
            p->tab[p->pos_y][p->pos_x] = 'O';
        } else if (p->tab[p->pos_y - 1][p->pos_x] != 'X'
            && p->tab[p->pos_y - 1][p->pos_x] != '#'){
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y - 1][p->pos_x] = 'P';
        }
    }
}

void mvdown(player_t *p)
{
    if (p->tab[p->pos_y + 1][p->pos_x] != '#') {
        if (p->tab[p->pos_y + 1][p->pos_x] == 'X'
            && p->tab[p->pos_y + 2][p->pos_x] != '#'
            && p->tab[p->pos_y + 2][p->pos_x] != 'X') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y + 2][p->pos_x] = 'X';
            p->tab[p->pos_y + 1][p->pos_x] = 'P';
        } else if (p->tab[p->pos_y + 1][p->pos_x] != 'X'
            && p->buff[p->pos_y][p->pos_x] == 'O') {
            p->tab[p->pos_y + 1][p->pos_x] = 'P';
            p->tab[p->pos_y][p->pos_x] = 'O';
        } else if (p->tab[p->pos_y + 1][p->pos_x] != 'X'
            && p->tab[p->pos_y + 1][p->pos_x] != '#') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y + 1][p->pos_x] = 'P';
        }
    }
}

void mvright(player_t *p)
{
    if (p->tab[p->pos_y][p->pos_x + 1] != '#') {
        if (p->tab[p->pos_y][p->pos_x + 1] == 'X'
            && p->tab[p->pos_y][p->pos_x + 2] != '#'
            && p->tab[p->pos_y][p->pos_x + 2] != 'X') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y][p->pos_x + 2] = 'X';
            p->tab[p->pos_y][p->pos_x + 1] = 'P';
        } else if (p->tab[p->pos_y][p->pos_x + 1] != 'X'
            && p->buff[p->pos_y][p->pos_x] == 'O') {
            p->tab[p->pos_y][p->pos_x] = 'O';
            p->tab[p->pos_y][p->pos_x + 1] = 'P';
        } else if (p->tab[p->pos_y][p->pos_x + 1] != 'X'
            && p->tab[p->pos_y][p->pos_x + 1] != '#') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y][p->pos_x + 1] = 'P';
        }
    }
}

void mvleft(player_t *p)
{
    if (p->tab[p->pos_y][p->pos_x - 1] != '#') {
        if (p->tab[p->pos_y][p->pos_x - 1] == 'X'
            && p->tab[p->pos_y][p->pos_x - 2] != '#'
            && p->tab[p->pos_y][p->pos_x - 2] != 'X') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y][p->pos_x - 2] = 'X';
            p->tab[p->pos_y][p->pos_x - 1] = 'P';
        } else if (p->tab[p->pos_y][p->pos_x - 1] != 'X'
            && p->buff[p->pos_y][p->pos_x] == 'O') {
            p->tab[p->pos_y][p->pos_x] = 'O';
            p->tab[p->pos_y][p->pos_x - 1] = 'P';
        } else if (p->tab[p->pos_y][p->pos_x - 1] != 'X'
            && p->tab[p->pos_y][p->pos_x - 1] != '#') {
            p->tab[p->pos_y][p->pos_x] = ' ';
            p->tab[p->pos_y][p->pos_x - 1] = 'P';
        }
    }
}

int move_p(player_t *p)
{
    p->key = getch();

    switch (p->key) {
        case KEY_UP:
            mvup(p);
            break;
        case KEY_DOWN:
            mvdown(p);
            break;
        case KEY_LEFT:
            mvleft(p);
            break;
        case KEY_RIGHT:
            mvright(p);
            break;
        default:
            break;
    }
    return (p->key);
}