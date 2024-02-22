/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task06 - compares two strings lexicographically
*/
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}
