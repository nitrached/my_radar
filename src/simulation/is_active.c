/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** is_active
*/
#include "my_radar.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

int is_active(nbr_aircraft_t *nbr_aircraft, simulation_t *simulation)
{
    nbr_aircraft_t *begin = nbr_aircraft;
    my_radar_t *current = begin->start;
    sfInt64 microsecond;
    sfTime elapseds;
    float second;

    elapseds = sfClock_getElapsedTime(simulation->clock);
    microsecond = elapseds.microseconds;
    second = microsecond / 1000000.0f;
    while (current != NULL) {
        if (current->data->delay <= second)
            current->data->is_active = 1;
        current = current->next;
    }
    return 0;
}
