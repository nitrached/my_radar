/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** add_tower
*/
#include "my_radar.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int add_node_tower(radar_tower_t *new_node,
    nbr_tower_t *begin, char **args)
{
    new_node = malloc(sizeof(radar_tower_t));
    new_node->data_tower = malloc(sizeof(tower_t));
    new_node->data_tower->pos_tower = malloc(sizeof(pos_t));
    new_node->next = begin->start;
    new_node->data_tower->id = begin->cpt;
    new_node->data_tower->pos_tower->x = my_getnbr(args[1]);
    new_node->data_tower->pos_tower->y = my_getnbr(args[2]);
    new_node->data_tower->radius = my_getnbr(args[3]);
    new_node->data_tower->texture =
        sfTexture_createFromFile("src/spt/tower.png", NULL);
    new_node->data_tower->sprite = sfSprite_create();
    sfSprite_setTexture(new_node->data_tower->sprite,
        new_node->data_tower->texture, sfTrue);
    begin->cpt += 1;
    begin->start = new_node;
    new_node = new_node->next;
    return 0;
}

int add_tower(char **individual_info, nbr_tower_t *tab_tower)
{
    nbr_tower_t *begin = tab_tower;
    radar_tower_t *new_node = NULL;

    add_node_tower(new_node, begin, individual_info);
    return 0;
}
