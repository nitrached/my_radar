/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** add_aircraft
*/
#include "my_radar.h"
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static void add_info_to_node(my_radar_t *new_node,
    nbr_aircraft_t *begin, char **args)
{
    new_node->data->pos->x = my_getnbr(args[1]);
    new_node->data->pos->y = my_getnbr(args[2]);
    new_node->data->pos_arrival.x = my_getnbr(args[3]);
    new_node->data->pos_arrival.y = my_getnbr(args[4]);
    new_node->data->speed = my_getnbr(args[5]);
    new_node->data->delay = my_getnbr(args[6]);
    new_node->data->texture = sfTexture_createFromFile("src/spt/p.png", NULL);
    new_node->data->sprite = sfSprite_create();
    sfSprite_setTexture(new_node->data->sprite,
        new_node->data->texture, sfTrue);
    new_node->data->clock = sfClock_create();
    begin->cpt += 1;
    new_node->data->is_active = 0;
    new_node->data->is_alive = 1;
}

static void add_node_aircraft(my_radar_t *new_node,
    nbr_aircraft_t *begin, char **args)
{
    new_node = malloc(sizeof(my_radar_t));
    new_node->data = malloc(sizeof(aircraft_t));
    new_node->data->pos = malloc(sizeof(pos_t));
    new_node->next = begin->start;
    new_node->prev = NULL;
    new_node->data->id = begin->cpt;
    add_info_to_node(new_node, begin, args);
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    begin->start = new_node;
}

int add_aircraft(char **individual_info, nbr_aircraft_t *nbr_aircraft)
{
    my_radar_t *new_node = NULL;
    nbr_aircraft_t *begin = nbr_aircraft;

    add_node_aircraft(new_node, begin, individual_info);
    return 0;
}
