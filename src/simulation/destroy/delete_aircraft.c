/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** delete_aircraft
*/
#include "my_radar.h"
#include "math.h"
#include <stdlib.h>

int is_to_delete(my_radar_t *current,
    nbr_aircraft_t *begin)
{
    current->data->is_alive = 0;
    if (current->prev == NULL && current->next == NULL) {
        begin->start = NULL;
        return 0;
    }
    if (current->prev == NULL) {
        begin->start = current->next;
        begin->start->prev = NULL;
    } else if (current->next == NULL) {
        current->prev->next = NULL;
    } else {
        current->next->prev = current->prev;
        current->prev->next = current->next;
    }
    return 0;
}

int delete_aircraft(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower)
{
    delete_arrival(nbr_aircraft);
    delete_colision(nbr_aircraft, tab_tower);
    return 0;
}
