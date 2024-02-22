/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Task08 - compares two strings lexicographically
*/
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return 0;
    while (i < n && s1[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    if (n <= i)
        i--;
    return s1[i] - s2[i];
}
