/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** draw_hitbox
*/
#include "my_radar.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

static void draw_radius_tower(nbr_tower_t *nbr_tower, simulation_t *simulation)
{
    nbr_tower_t *begin = nbr_tower;
    radar_tower_t *current = begin->start;
    sfCircleShape *radius = sfCircleShape_create();

    while (current != NULL) {
        sfCircleShape_setRadius(radius, current->data_tower->radius /
            100 * 1920);
        sfCircleShape_setOrigin(radius, (sfVector2f)
            {current->data_tower->radius / 100 * 1920,
            current->data_tower->radius / 100 * 1920});
        sfCircleShape_setPosition(radius, (sfVector2f){
            current->data_tower->pos_tower->x,
            current->data_tower->pos_tower->y});
        sfCircleShape_setOutlineColor(radius, sfBlack);
        sfCircleShape_setOutlineThickness(radius, 1.0);
        sfCircleShape_setFillColor(radius, sfTransparent);
        sfRenderWindow_drawCircleShape(simulation->window, radius, NULL);
        current = current->next;
    }
    current = begin->start;
}

static int draw_hitbox_plane(nbr_aircraft_t *nbr_aircraft,
    simulation_t *simulation, float seconds)
{
    nbr_aircraft_t *begin = nbr_aircraft;
    my_radar_t *current = begin->start;
    sfRectangleShape *hitbox = sfRectangleShape_create();

    while (current != NULL) {
        if (current->data->delay <= seconds) {
            sfRectangleShape_setPosition(hitbox, (sfVector2f)
                {current->data->pos->x - 10, current->data->pos->y - 10});
            sfRectangleShape_setSize(hitbox, (sfVector2f){20, 20});
            sfRectangleShape_setOutlineThickness(hitbox, 1.0);
            sfRectangleShape_setFillColor(hitbox, sfTransparent);
            sfRectangleShape_setOutlineColor(hitbox, sfBlack);
            sfRenderWindow_drawRectangleShape(simulation->window,
                hitbox, NULL);
            }
        current = current->next;
    }
    current = begin->start;
    return 0;
}

int draw_hitbox(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower,
    simulation_t *simulation, int *is_to_print_hitbox)
{
    sfInt64 microseconds;
    sfTime elapsed;
    float seconds;

    elapsed = sfClock_getElapsedTime(simulation->clock);
    microseconds = elapsed.microseconds;
    seconds = microseconds / 1000000.0f;
    if (*is_to_print_hitbox) {
        draw_hitbox_plane(nbr_aircraft, simulation, seconds);
        draw_radius_tower(tab_tower, simulation);
    }
    return 0;
}
