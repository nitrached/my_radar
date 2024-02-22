/*
** EPITECH PROJECT, 2023
** Day05-Recursivity
** File description:
** Task05 - returns the square root of nb
*/
int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return 0;
    if (nb == 1)
        return 1;
    for (int i = 1; i <= nb / 2; i++) {
        if ((nb % i) == 0 && (nb / i == i))
            return i;
    }
    return 0;
}
