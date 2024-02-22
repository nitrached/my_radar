/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** create_window
*/
#include "my_radar.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};

    return sfRenderWindow_create(mode, "my radar", sfResize | sfClose, NULL);
}
