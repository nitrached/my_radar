/*
** EPITECH PROJECT, 2023
** Day04-Pointers
** File description:
** Task02 - Print string
*/
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    while (*str != '\0') {
        write(1, str++, 1);
    }
    return 0;
}
