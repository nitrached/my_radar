/*
** EPITECH PROJECT, 2023
** Day08-Compilation, Allocation
** File description:
** Task01 - allocate memory and copies string
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *out;
    int i = 0;
    int size = my_strlen(src);

    if (size == 0)
        return NULL;
    out = malloc(size +1);
    if (out == NULL)
        return NULL;
    for (; src[i] != '\0'; i++)
        out[i] = (char)src[i];
    out[i] = '\0';
    return out;
}
