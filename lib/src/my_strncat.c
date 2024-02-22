/*
** EPITECH PROJECT, 2023
** Day07-Libmy, arguments
** File description:
** Task02 - concatenate two strings
** non-printable characters are printed hexadecimally
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;

    for (; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0' && j < nb; j++)
        dest[i +j] = src[j];
    return dest;
}
