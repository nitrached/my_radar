/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** handle_event
*/

#include "my_radar.h"

static int modify_speed(simulation_t *simulation, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI) {
        if (simulation->speed_ratio == 1.0) {
            simulation->speed_ratio = 2;
            return 0;
        }
        if (simulation->speed_ratio != 1 && simulation->speed_ratio < 20)
            simulation->speed_ratio += 2;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD) {
        if (simulation->speed_ratio == 2.0) {
            simulation->speed_ratio = 1;
            return 0;
        }
        if (simulation->speed_ratio != 1)
            simulation->speed_ratio = simulation->speed_ratio - 2;
    }
    return 0;
}

int handle_events(simulation_t *simulation, int *is_to_print,
    int *is_to_print_hitbox)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(simulation->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(simulation->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            *is_to_print = !*is_to_print;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
            *is_to_print_hitbox = !*is_to_print_hitbox;
        modify_speed(simulation, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
            simulation->pause = !simulation->pause;
        }
    }
    return 0;
}
