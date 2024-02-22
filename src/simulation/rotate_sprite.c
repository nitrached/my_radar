/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** rotate_sprite
*/
#include "my_radar.h"
#include "math.h"

int rotate_sprite(float dx, float dy, my_radar_t *current)
{
    float angle = atan2(dy, dx);
    float degrees = angle * (180 / M_PI);

    sfSprite_setRotation(current->data->sprite, degrees);
    return 0;
}
