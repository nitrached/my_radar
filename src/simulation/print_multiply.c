/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** print_multiply
*/
#include "my_radar.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

void print(simulation_t *simulation)
{
    sfFont *font = sfFont_createFromFile("src/spt/Milk_Mango.otf");
    sfText *sentence = sfText_create();
    sfText *multiply = sfText_create();

    sfText_setString(sentence, "multiply by x");
    sfText_setString(multiply, int_to_char(simulation->speed_ratio));
    sfText_setFont(sentence, font);
    sfText_setFont(multiply, font);
    sfText_setCharacterSize(sentence, 40);
    sfText_setCharacterSize(multiply, 40);
    sfText_setColor(sentence, sfBlack);
    sfText_setColor(multiply, sfBlack);
    sfText_setPosition(sentence, (sfVector2f){0, 0});
    sfText_setPosition(multiply, (sfVector2f){300, 0});
    sfRenderWindow_drawText(simulation->window, sentence, NULL);
    sfRenderWindow_drawText(simulation->window, multiply, NULL);
}
