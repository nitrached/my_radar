/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** draw_entity
*/
#include <stdio.h>
#include "my_radar.h"

static int draw_tower(nbr_tower_t *nbr_tower, simulation_t *simulation)
{
    nbr_tower_t *begin = nbr_tower;
    radar_tower_t *current = begin->start;
    int i = 0;

    while (current != NULL) {
            sfSprite_setPosition(current->data_tower->sprite,
                (sfVector2f){current->data_tower->pos_tower->x,
                current->data_tower->pos_tower->y});
            sfSprite_setOrigin(current->data_tower->sprite,
                (sfVector2f){512 / 2, 512 / 2});
            sfRenderWindow_drawSprite(simulation->window,
                current->data_tower->sprite, NULL);
            sfSprite_setScale(current->data_tower->sprite,
                (sfVector2f){0.15, 0.15});
            current = current->next;
            i++;
        }
    current = begin->start;
    return 0;
}

static int draw_plane(nbr_aircraft_t *nbr_aircraft, simulation_t *simulation)
{
    nbr_aircraft_t *begin = nbr_aircraft;
    my_radar_t *current = begin->start;

    while (current != NULL) {
        if (current->data->is_active) {
            sfSprite_setOrigin(current->data->sprite,
                (sfVector2f){285 / 2, 268 / 2});
            sfSprite_setPosition(current->data->sprite,
                (sfVector2f){current->data->pos->x, current->data->pos->y});
            sfSprite_setScale(current->data->sprite, (sfVector2f){0.07, 0.07});
            sfRenderWindow_drawSprite(simulation->window,
                current->data->sprite, NULL);
            }
        current = current->next;
    }
    current = begin->start;
    return 0;
}

int draw_entity(nbr_aircraft_t *nbr_aircraft,
    nbr_tower_t *nbr_tower, simulation_t *simulation, int *is_to_print)
{
    sfRenderWindow_drawSprite(simulation->window, simulation->sprite, NULL);
    if (*is_to_print) {
        draw_tower(nbr_tower, simulation);
        draw_plane(nbr_aircraft, simulation);
    }
    return 0;
}
