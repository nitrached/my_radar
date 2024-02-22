/*
** EPITECH PROJECT, 2023
** Day05-Recursivity
** File description:
** Task06 - test if number is prime
*/
static int greater_sqrt(int nb)
{
    int i = 1;

    if (nb <= 0)
        return 0;
    while (i * i < nb)
        i++;
    return i;
}

int my_is_prime(int nb)
{
    if (nb <= 1)
        return 0;
    for (int i = 2; i <= greater_sqrt(nb); i++)
        if ((nb % i == 0) && i != nb)
            return 0;
    return 1;
}
