/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main
*/

#include "my_radar.h"
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"
#include <stdio.h>

static int error_case(int argc, char **argv)
{
    struct stat filestat;

    if (argc != 2)
        return 84;
    if (stat(argv[1], &filestat) < 0 && (S_ISREG(filestat.st_mode)
        == 0 && my_strcmp(argv[1], "-h") != 0))
        return 84;
    return 0;
}

static void destroy_game(simulation_t *simulation)
{
    sfClock_destroy(simulation->clock);
    sfSprite_destroy(simulation->sprite);
    sfTexture_destroy(simulation->texture);
    sfRenderWindow_close(simulation->window);
    sfRenderWindow_destroy(simulation->window);
}

int main(int argc, char **argv)
{
    nbr_aircraft_t nbr_aircraft = innit_aircraft();
    nbr_tower_t tab_tower = innit_tower();
    simulation_t simulation;

    if (error_case(argc, argv) == 84)
        return 84;
    if (is_h(argv[1]) == 1)
        return 0;
    if (get_info(argv[1], &nbr_aircraft, &tab_tower) == 84) {
        mini_printf("error in script\n");
        return 84;
    }
    simulation = innit_simu();
    sfRenderWindow_setFramerateLimit(simulation.window, 60);
    if (play_simulation(&nbr_aircraft, &tab_tower, &simulation) == 84) {
        destroy_game(&simulation);
        return 84;
    }
    destroy_game(&simulation);
    return 0;
}
