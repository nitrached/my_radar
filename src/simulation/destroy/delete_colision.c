/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** delete_colision
*/
#include "my_radar.h"
#include "math.h"
#include <stdlib.h>

static int is_in_tower(my_radar_t *current, nbr_tower_t *tab_tower)
{
    nbr_tower_t *begin = tab_tower;
    radar_tower_t *current_tower = begin->start;
    float distance;

    for (int i = 0; i < begin->cpt; i++) {
        distance = sqrt(pow(current->data->pos->x -
            current_tower->data_tower->pos_tower->x, 2) +
            pow(current->data->pos->y -
            current_tower->data_tower->pos_tower->y, 2));
        if (distance <= current_tower->data_tower->radius / 100 * 1920)
            return 1;
        current_tower = current_tower->next;
    }
    return 0;
}

static int is_superimpose(nbr_aircraft_t *begin, my_radar_t *current)
{
    my_radar_t *savior = begin->start;

    while (savior != NULL) {
        if (savior->data->id != current->data->id &&
            (current->data->pos->x + 20) >= savior->data->pos->x &&
            current->data->pos->x <= (savior->data->pos->x + 20) &&
            (current->data->pos->y + 20) >= savior->data->pos->y &&
            current->data->pos->y <= (savior->data->pos->y + 20) &&
            savior->data->is_active && savior->data->is_alive) {
            is_to_delete(current, begin);
            is_to_delete(savior, begin);
        }
        savior = savior->next;
    }
    savior = begin->start;
    return 0;
}

int delete_colision(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower)
{
    nbr_aircraft_t *begin = nbr_aircraft;
    my_radar_t *current = begin->start;

    while (current != NULL) {
        if (!is_in_tower(current, tab_tower) && current->data->is_active
            && current->data->is_alive) {
            is_superimpose(begin, current);
        }
        current = current->next;
    }
    return 0;
}
