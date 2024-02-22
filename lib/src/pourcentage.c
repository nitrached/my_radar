/*
** EPITECH PROJECT, 2023
** print pourcent
** File description:
** quand il y a un % print un %
*/

#include "my.h"
#include "struct_mini_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int print_pourcent(va_list args)
{
    (void)args;
    my_putchar('%');
    return 1;
}
