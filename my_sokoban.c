/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** my_sokoban
*/

#include "include/my.h"

char *fs_open_file(char *filepath)
{
    struct stat stats;
    stat(filepath, &stats);
    char *tab = malloc(sizeof(char) * (stats.st_size + 1));
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || fd == 0)
        exit (84);
    if (read(fd, tab, stats.st_size) != stats.st_size)
        exit (84);
    if (check_map(tab) == 84)
        return (NULL);
    tab[stats.st_size] = '\0';
    close(fd);
    return (tab);
}

int num_lines(char *str)
{
    int nbline = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nbline += 1;
    }
    return (nbline);
}

char **my_str_to_arr(char *str)
{
    char **tab;
    int lines = num_lines(str);
    int count = 0;

    tab = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0, a = 0; i < lines; i++) {
        for (count = 0; str[a] != '\n' && str[a] != '\0'; count++, a++);
            tab[i] = malloc(sizeof(char) * (count + 1));
        a++;
    }
    for (int y = 0, x = 0, i = 0; y < lines; y++, i++) {
        for (x = 0; str[i] != '\n'; x++, i++)
            tab[y][x] = str[i];
        tab[y][x] = '\n';
    }
    tab[lines] = NULL;
    return (tab);
}