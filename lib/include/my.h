/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my
*/

#ifndef NO_USE_MY
    #define NO_USE_MY

    #include "struct_mini_printf.h"
    #include <dirent.h>


void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_printf(const char *restrict format, ...);
char *fill_malloc(char *str, char *str_slash, int len);
char get_specifier(const char *str);
char **slash_string(int cpt);
int correct_letter(const char *format, va_list args, int cpt, int i);
int mini_printf(const char *format, ...);
void print_directory(char **all_directory_file);
char *my_char_realloc(char *old_char, char caract_to_add);
char **my_realloc(char **old_tab, char *lign_to_add);
char *fill_malloc(char *name, char *str_name, int len);
int give_info(char **tab_argv, int cpt);
char **get_give_directory(char *argv, int cpt);
char **my_str_to_word_array(const char *str, char delimiter);
char *int_to_char(int number);

#endif
