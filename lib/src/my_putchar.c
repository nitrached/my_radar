/*
** EPITECH PROJECT, 2023
** Day03-First C Programming
** File description:
** Task07 - Print number
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
