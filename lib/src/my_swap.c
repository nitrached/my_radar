/*
** EPITECH PROJECT, 2023
** Day04-Pointers
** File description:
** Task01 - swap the content of two integers
*/
void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
