/*
** EPITECH PROJECT, 2023
** Day03-First C Programming
** File description:
** Task04 - return 'P' or 'N' if number is negative
*/
#include "my.h"

int my_isneg(int n)
{
    my_putstr(n < 0 ? "N\n" : "P\n");
    return 0;
}
