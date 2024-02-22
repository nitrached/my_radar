/*
** EPITECH PROJECT, 2023
** print un integer
** File description:
** affiche un integer qui peut changer
*/

#include "my.h"
#include "struct_mini_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int print_integer(va_list args)
{
    int length = 0;
    int arg = va_arg(args, int);

    my_put_nbr(arg);
    while (arg > 0) {
        arg = arg / 10;
        length++;
    }
    return length;
}
