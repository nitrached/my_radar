/*
** EPITECH PROJECT, 2023
** Day03-First C Programming
** File description:
** Task07 - Print number
*/
#include "my.h"

static int get_digit(int number, int digit)
{
    while (0 < digit) {
        number /= 10;
        digit--;
    }
    return number % 10;
}

static int get_length(int num)
{
    int n = 0;

    if (num == 0)
        return 1;
    while (0 < num) {
        num /= 10;
        n++;
    }
    return n;
}

int my_put_nbr(int nb)
{
    int is_int_min = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb == -2147483648) {
        nb = 2147483647;
        is_int_min = 1;
    }
    for (int i = get_length(nb)-1; 0 <= i; i--) {
        my_putchar(get_digit(nb, i) + ((is_int_min && (i == 0)) ? 49 : 48));
    }
    return 0;
}
