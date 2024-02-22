/*
** EPITECH PROJECT, 2023
** print char
** File description:
** print un char
*/

#include "my.h"
#include "struct_mini_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int print_char(va_list args)
{
    int arg = (char)va_arg(args, int);

    my_putchar(arg);
    return 1;
}
