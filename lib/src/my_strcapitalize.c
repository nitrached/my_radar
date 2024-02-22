/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task08 - put every letter of string in uppercase
*/
static int is_sep(char c)
{
    if (c == ' ' || c == '-' || c == '+')
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    char prev = ' ';

    while (str[i] != '\0') {
        if (is_sep(prev) && ('a' <= str[i] && str[i] <= 'z'))
            str[i] -= 32;
        if (!is_sep(prev) && ('A' <= str[i] && str[i] <= 'Z'))
            str[i] += 32;
        i++;
        prev = str[i];
    }
    return str;
}
