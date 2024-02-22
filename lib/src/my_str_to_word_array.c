/*
** EPITECH PROJECT, 2023
** my str to word array
** File description:
** pass a str into an array
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char get_char_at_position(const char *str, int word_index,
    int char_index, char separator)
{
    int i = 0;
    int spaces = 1;
    int num_spaces = 0;
    int letters = 0;

    while (str[i] != '\0') {
        if (spaces == 1 && str[i] != separator) {
            spaces = 0;
            num_spaces++;
        }
        spaces = (str[i] == separator) ? 1 : 0;
        letters += (str[i] != separator && num_spaces == word_index) ? 1 : 0;
        if (letters == char_index)
            return str[i];
        i++;
    }
    return '\0';
}

int count_chars_in_word(const char *str, int word_index, char separator)
{
    int i = 0;
    int spaces = 1;
    int num_spaces = 0;
    int letters = 0;

    while (str[i] != '\0') {
        if (spaces == 1 && str[i] != separator) {
            spaces = 0;
            num_spaces++;
        }
        spaces = (str[i] == separator) ? 1 : 0;
        letters += (str[i] != separator && num_spaces == word_index) ? 1 : 0;
        i++;
    }
    return letters;
}

int count_words(const char *str, char separator)
{
    int i = 0;
    int spaces = 1;
    int num_words = 0;

    while (str[i] != '\0') {
        if (spaces == 1 && str[i] != separator) {
            spaces = 0;
            num_words++;
        }
        spaces = (str[i] == separator) ? 1 : 0;
        i++;
    }
    return num_words;
}

char **my_str_to_word_array(const char *str, char separator)
{
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * (count_words(str, separator) + 1));

    while (i < count_words(str, separator)) {
        tab[i] = malloc(sizeof(char) * (count_chars_in_word
            (str, i + 1, separator) + 1));
        j = 0;
        while (j < count_chars_in_word(str, i + 1, separator)) {
            tab[i][j] = get_char_at_position(str, i + 1, j + 1, separator);
            j++;
        }
        tab[i][j] = '\0';
        i++;
    }
    tab[i] = 0;
    return tab;
}
