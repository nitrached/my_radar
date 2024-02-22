/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** get_direction
*/
#include "my_radar.h"
#include "math.h"

float get_direct(my_radar_t *current, int i)
{
    float dx = current->data->pos_arrival.x - current->data->pos->x;
    float dy = current->data->pos_arrival.y - current->data->pos->y;
    float directionx;
    float directiony;
    float magn = sqrt(dx * dx + dy * dy);

    directionx = dx / magn;
    directiony = dy / magn;
    rotate_sprite(dx, dy, current);
    if (i == 1)
        return directionx;
    if (i == 2)
        return directiony;
    return 0.0;
}
