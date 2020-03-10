/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** my
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <ncurses.h>

#ifndef MY_H_
#define MY_H_

typedef struct player_s {
    int nb_lines;
    int pos_x;
    int pos_y;
    char **tab;
    int key;
    char **buff;
} player_t;

int help(int ac, char **av);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char **my_str_to_arr(char *str);
char *fs_open_file(char *filepath);
int num_lines(char *str);
int check_error(int ac);
void game(char **av, player_t *p);
int move_p(player_t *p);
void find_p(player_t *p);
void reset(char **av, player_t *p);
int my_declaration(char **av, player_t *p);
int check_map(char *str);

#endif /* !MY_H_ */