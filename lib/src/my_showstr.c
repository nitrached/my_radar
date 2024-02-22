/*
** EPITECH PROJECT, 2023
** Day04-Pointers
** File description:
** Task20 - prints a string and returns 0.
** non-printable characters are printed hexadecimally
*/
#include "my.h"

static char *to_hexa(short nb, char *out)
{
    int i = nb & ((1 << 4) -1);

    out[0] = '\\';
    out[2] = i < 10 ? i + '0' : i -10 + 'a';
    i = nb >> 4 & ((1 << 4) -1);
    out[1] = i < 10 ? i + '0' : i -10 + 'a';
    return out;
}

int my_showstr(char const *str)
{
    char temp[3] = {'\\'};

    for (; *str != '\0'; str++) {
        if (' ' <= *str && *str <= '~')
            my_putchar(*str);
        else
            my_putstr(to_hexa(*str, temp));
    }
    return 0;
}
