/*
** EPITECH PROJECT, 2023
** print string
** File description:
** print un string
*/

#include "my.h"
#include "struct_mini_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int print_string(va_list args)
{
    char *arg = va_arg(args, char *);

    my_putstr(arg);
    return my_strlen(arg);
}
