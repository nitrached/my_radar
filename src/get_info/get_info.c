/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get_info
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "my_radar.h"

static char *open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat filestat;
    char *buff = NULL;

    if (stat(filepath, &filestat) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (filestat.st_size + 1));
    read(fd, buff, filestat.st_size);
    close(fd);
    buff[filestat.st_size] = '\0';
    return buff;
}

static int is_enought_arg(char **individual_info)
{
    int i = 0;

    while (individual_info[i] != NULL) {
        i++;
    }
    return i;
}

static int check_if_a_t(char *info, nbr_aircraft_t *nbr_aircraft,
    nbr_tower_t *tab_tower)
{
    char **individual_info = my_str_to_word_array(info, ' ');

    for (int i = 1; individual_info[i] != NULL; i++) {
        if (my_str_isnum(individual_info[i]) == 0)
            return 84;
    }
    if (my_strcmp(individual_info[0], "A") == 0) {
        if (is_enought_arg(individual_info) != 7)
            return 84;
        add_aircraft(individual_info, nbr_aircraft);
        return 0;
    }
    if (my_strcmp(individual_info[0], "T") == 0) {
        if (is_enought_arg(individual_info) != 4)
            return 84;
        add_tower(individual_info, tab_tower);
        return 0;
    }
    return 84;
}

int get_info(char *filepath, nbr_aircraft_t *nbr_aircraft,
    nbr_tower_t *tab_tower)
{
    char *arg = open_file(filepath);
    char **info = my_str_to_word_array(arg, '\n');

    for (int i = 0; info[i] != NULL; i++) {
        if (check_if_a_t(info[i], nbr_aircraft, tab_tower) == 84)
            return 84;
    }
    return 0;
}
