/*
** EPITECH PROJECT, 2023
** Day04-Pointers
** File description:
** Task03 - return length of string
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return count;
}
