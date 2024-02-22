/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** innit
*/
#include "my_radar.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

nbr_aircraft_t innit_aircraft(void)
{
    nbr_aircraft_t nbr_aircraft;

    nbr_aircraft.start = NULL;
    nbr_aircraft.cpt = 0;
    return nbr_aircraft;
}

nbr_tower_t innit_tower(void)
{
    nbr_tower_t nbr_tower;

    nbr_tower.start = NULL;
    nbr_tower.cpt = 0;
    return nbr_tower;
}

simulation_t innit_simu(void)
{
    simulation_t simulation;

    simulation.window = create_window();
    simulation.clock = sfClock_create();
    simulation.texture = sfTexture_createFromFile("src/spt/hearth.png", NULL);
    simulation.sprite = sfSprite_create();
    sfSprite_setTexture(simulation.sprite,
        simulation.texture, sfTrue);
    simulation.speed_ratio = 1;
    simulation.pause = 1;
    return simulation;
}
