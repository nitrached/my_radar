/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** delete_arrival
*/
#include "my_radar.h"
#include "math.h"
#include <stdlib.h>

static int condition_arrival(nbr_aircraft_t *begin, my_radar_t *current)
{
    if ((current->data->is_active && current->data->is_alive &&
            current->data->pos->x > current->data->pos_arrival.x -
            current->data->speed && current->data->pos->x <
            current->data->pos_arrival.x +
            current->data->speed && current->data->pos->y >
            current->data->pos_arrival.y - current->data->speed &&
            current->data->pos->y < current->data->pos_arrival.y +
            current->data->speed) || (current->data->pos->x ==
            current->data->pos_arrival.x && current->data->pos->y ==
            current->data->pos_arrival.y && current->data->is_active &&
            current->data->is_alive)) {
            is_to_delete(current, begin);
    }
    return 0;
}

int delete_arrival(nbr_aircraft_t *nbr_aircraft)
{
    nbr_aircraft_t *begin = nbr_aircraft;
    my_radar_t *current = begin->start;
    int i = 0;

    while (current != NULL){
        condition_arrival(begin, current);
        if (current != NULL)
            current = current->next;
        i++;
    }
    return 0;
}
