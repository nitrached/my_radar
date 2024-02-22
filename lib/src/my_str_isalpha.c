/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task12 - string contains only alphabet chars
*/
int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(('a' <= str[i] && str[i] <= 'z') ||
            ('A' <= str[i] && str[i] <= 'Z')))
            return 0;
        i++;
    }
    return 1;
}
