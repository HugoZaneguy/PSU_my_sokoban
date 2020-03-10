/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** main
*/

#include "include/my.h"
#include <ncurses.h>

int my_declaration(char **av, player_t *p)
{
    char *map = fs_open_file(av[1]);
    if (!map) {
        return (84);
    }
    p->nb_lines = num_lines(map);
    p->tab = my_str_to_arr(map);
    p->buff = my_str_to_arr(map);
}

void find_p(player_t *p)
{
    for (int y = 0; y < p->nb_lines; y++) {
        for (int x = 0; p->tab[y][x] != '\n' &&
            p->tab[y][x] != '\0'; x++) {
            if (p->tab[y][x] == 'P') {
                p->pos_y = y;
                p->pos_x = x;
            }
        }
    }
}

void game(char **av, player_t *p)
{
    my_declaration(av, p);
    initscr();
    clear();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    while (1) {
        find_p(p);
        for (int i = 0; i < p->nb_lines; i++)
            mvprintw(i + (LINES / 2.5), (COLS / 2.2), "%s", p->tab[i]);
        refresh();
        move_p(p);
        reset(av, p);
    }
    endwin();
}

int main(int ac, char **av)
{
    player_t *p = malloc(sizeof(player_t));
    if (ac == 2) {
        help(ac, av);
    }
    check_error(ac);
    game(av, p);

    free(p);
    return (0);
}