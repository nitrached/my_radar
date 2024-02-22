/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task12 - string contains only alphabet chars
*/
int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!('0' <= str[i] && str[i] <= '9'))
            return 0;
        i++;
    }
    return 1;
}
