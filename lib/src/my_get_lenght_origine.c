/*
** EPITECH PROJECT, 2023
** my get origine
** File description:
** recupere ma string d'origine
** et la coupe en morceau de chaque modulo
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct_ls.h"
#include <dirent.h>

char **no_a(DIR *open, struct_ls *tab)
{
    struct dirent *read;
    char *name;
    int len;

    read = readdir(open);
    while (read != NULL) {
        name = read->d_name;
        if (name[0] != '.') {
            len = my_strlen(read->d_name);
            malloc_slash_string(name, len, tab);
        }
        read = readdir(open);
    }
    return tab->arg;
}

char **is_a(DIR *open, struct_ls *tab)
{
    struct dirent *read;
    char *name;
    int len;

    read = readdir(open);
    while (read != NULL) {
        name = read->d_name;
        len = my_strlen(read->d_name);
        malloc_slash_string(name, len, tab);
        read = readdir(open);
    }
    return tab->arg;
}

char **slash_string(int cpt)
{
    struct_ls *tab = tab_ls_init();
    DIR *open;

    open = opendir(".");
    if (open != NULL) {
        if (cpt == 0)
            no_a(open, tab);
        if (cpt != 0)
            is_a(open, tab);
    }
    closedir(open);
    return tab->arg;
}
