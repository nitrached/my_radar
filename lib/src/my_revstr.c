/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task03 - reverses a string
*/
#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int len = my_strlen(str);

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len -i -2];
        str[len -i -2] = temp;
    }
    return str;
}
