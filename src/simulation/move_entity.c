/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** move_entity
*/
#include "my_radar.h"
#include <stdio.h>

int condition(my_radar_t *current, simulation_t *simulation)
{
    sfInt64 microseconds;
    sfTime elapsed;
    float seconds;

    elapsed = sfClock_getElapsedTime(current->data->clock);
    microseconds = elapsed.microseconds;
    seconds = microseconds / 1000000.0f;
    if (current->data->is_active) {
        current->data->pos->x += current->data->speed * seconds
            * get_direct(current, 1) * simulation->speed_ratio *
            simulation->pause;
        current->data->pos->y += current->data->speed * seconds
            * get_direct(current, 2) * simulation->speed_ratio *
            simulation->pause;
    }
    sfClock_restart(current->data->clock);
    return 0;
}

int move_entity(nbr_aircraft_t *nbr_aircraft, simulation_t *simulation)
{
    nbr_aircraft_t *begin = nbr_aircraft;
    my_radar_t *current = begin->start;

    while (current != NULL) {
        condition(current, simulation);
        current = current->next;
    }
    current = begin->start;
    if (current == NULL)
        return 1;
    return 0;
}
