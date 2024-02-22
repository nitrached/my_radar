/*
** EPITECH PROJECT, 2023
** fill malloc
** File description:
** fill a malloc string with another string
*/

char *fill_malloc(char *name, char *str_slash, int len)
{
    int i = 0;

    while (i < len) {
        str_slash[i] = name[i];
        i++;
    }
    str_slash[i] = '\0';
    return str_slash;
}
