/*
** EPITECH PROJECT, 2023
** Day05-Recursivity
** File description:
** Task07 - returns smallest prime number that is greater or equal to nb
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 1)
        nb = 2;
    while (!my_is_prime(nb))
        nb++;
    return nb;
}
