/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task08 - put every letter of string in uppercase
*/
char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return str;
}
