/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** timer
*/
#include "my_radar.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

static void print_clock(int minute, int seconds, simulation_t *simulation)
{
    sfFont *font = sfFont_createFromFile("src/spt/Milk_Mango.otf");
    sfText *minutes = sfText_create();
    sfText *second = sfText_create();

    sfText_setString(minutes, int_to_char(minute));
    sfText_setString(second, int_to_char(seconds));
    sfText_setFont(minutes, font);
    sfText_setFont(second, font);
    sfText_setCharacterSize(minutes, 50);
    sfText_setCharacterSize(second, 50);
    sfText_setColor(minutes, sfBlack);
    sfText_setColor(second, sfBlack);
    sfText_setPosition(minutes, (sfVector2f){1810, 0});
    sfText_setPosition(second, (sfVector2f){1855, 0});
    sfRenderWindow_drawText(simulation->window, minutes, NULL);
    sfRenderWindow_drawText(simulation->window, second, NULL);
}

int clock_timer(sfClock *timer, int *minute, simulation_t *simulation)
{
    sfTime elapsed;
    float seconds;
    int second;
    sfInt64 microseconds;

    elapsed = sfClock_getElapsedTime(timer);
    microseconds = elapsed.microseconds;
    seconds = microseconds / 1000000.0f;
    second = seconds;
    if (second > 59) {
        sfClock_restart(timer);
        *minute += 1;
    }
    print_clock(*minute, second, simulation);
    return 0;
}
