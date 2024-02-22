/*
** EPITECH PROJECT, 2023
** Day06-Pointers are back
** File description:
** Test - Task05 - finds the first occurrence of s2 in s1
*/
static int if_is_eqq(char *str, char const *to_find, int i)
{
    int j = 0;

    while (str[i + j] == to_find[j]) {
        if (to_find[j +1] == '\0')
            return 1;
        j++;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    char *out = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[0] && if_is_eqq(str, to_find, i))
            out = str + i;
        i++;
    }
    return out;
}
