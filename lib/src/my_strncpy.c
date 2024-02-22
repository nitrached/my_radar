/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task02 - copy n chars from a string into another
*/

#include <string.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
