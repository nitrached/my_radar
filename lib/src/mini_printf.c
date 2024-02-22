/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** fait %d %i %s %c %% du printf originel
*/

#include "my.h"
#include "struct_mini_printf.h"
#include <stdlib.h>
#include <stdarg.h>

const test_t MINI_PRINTF[] = {
    {'d', &print_integer},
    {'i', &print_integer},
    {'s', &print_string},
    {'c', &print_char},
    {'%', &print_pourcent},
};

int correct_letter(const char *format, va_list args, int cpt, int i)
{
    for (int a = 0; a < 5; a++) {
        if (MINI_PRINTF[a].letter == format[cpt])
            i += MINI_PRINTF[a].fonct(args);
    }
    return i;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    for (int cpt = 0; format[cpt] != '\0'; cpt++) {
        if (format[cpt] == '%') {
            cpt++;
            i = correct_letter(format, args, cpt, i);
        } else {
            my_putchar(format[cpt]);
            i++;
        }
    }
    va_end(args);
    return i;
}
