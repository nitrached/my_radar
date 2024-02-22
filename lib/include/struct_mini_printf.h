/*
** EPITECH PROJECT, 2023
** mini printf structure
** File description:
** mini printf structure
*/
#ifndef TEST_H_
    #define TEST_H_

    #include <stdarg.h>

typedef struct test_t {

    char letter;
    int (*fonct)(va_list);

} test_t;

int print_char(va_list args);
int print_integer(va_list args);
int print_string(va_list args);
int print_pourcent(va_list args);

#endif /* TEST_H_ */
