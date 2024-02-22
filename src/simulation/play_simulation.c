/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** play_simulation
*/
#include "my_radar.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

int play_simulation(nbr_aircraft_t *nbr_aircraft,
    nbr_tower_t *tab_tower, simulation_t *simulation)
{
    int is_to_print = 1;
    int is_to_print_hitbox = 1;
    sfClock *timer = sfClock_create();
    int minute = 0;

    while (sfRenderWindow_isOpen(simulation->window)) {
        is_active(nbr_aircraft, simulation);
        handle_events(simulation, &is_to_print, &is_to_print_hitbox);
        sfRenderWindow_clear(simulation->window, sfBlack);
        if (move_entity(nbr_aircraft, simulation) == 1)
            return 0;
        draw_entity(nbr_aircraft, tab_tower, simulation, &is_to_print);
        draw_hitbox(nbr_aircraft, tab_tower, simulation, &is_to_print_hitbox);
        clock_timer(timer, &minute, simulation);
        print(simulation);
        delete_aircraft(nbr_aircraft, tab_tower);
        sfRenderWindow_display(simulation->window);
    }
    return 0;
}
