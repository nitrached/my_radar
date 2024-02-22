/*
** EPITECH PROJECT, 2023
** malloc length origine
** File description:
** malloc the length of the string that will be in my tab
*/

#include "struct_ls.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <dirent.h>

struct_ls *tab_ls_init(void)
{
    struct_ls *tab = malloc(sizeof(struct_ls));

    if (tab == NULL)
        exit(EXIT_FAILURE);
    tab->length = 0;
    tab->arg = malloc(sizeof(char *) * (tab->length + 1));
    tab->arg[0] = NULL;
    if (tab->arg == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour tab->arg");
        free(tab);
        exit(EXIT_FAILURE);
    }
    return tab;
}

struct_ls *malloc_slash_string(char *name, int len, struct_ls *tab)
{
    char *str_slash = malloc(sizeof(char) * (len + 1));

    if (str_slash == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    str_slash = fill_malloc(name, str_slash, len);
    tab->arg = my_realloc(tab->arg, str_slash);
    tab->length += 1;
    free(str_slash);
    return tab;
}
