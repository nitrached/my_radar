/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task01 - copy a string into another
*/
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}
