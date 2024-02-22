/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task08 - put every letter of string in uppercase
*/
char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
