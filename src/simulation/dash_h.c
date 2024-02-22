/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** dash_h
*/
#include "my_radar.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

int is_h(char *argv1)
{
    if (my_strcmp(argv1, "-h") == 0) {
        mini_printf("Air traffic simulation panel\n\n");
        mini_printf("USAGE\n\t");
        mini_printf("./my_radar [OPTIONS] path_to_script\n");
        mini_printf("path_to_script\tThe path to the script file.\n\n");
        mini_printf("OPTIONS\n");
        mini_printf("\t-h print the usage and quit.\n\n");
        mini_printf("USER INTERACTIONS\n");
        mini_printf("\t'L' key\tenable/disable hitboxes and areas.\n");
        mini_printf("\t'S' key\tenable/disable sprites.\n");
        mini_printf("\t'P' Key\tprevent the airplanes to move.\n");
        mini_printf("\t'I' Key\tincrease the speed of the airplanes ");
        mini_printf("(maximum x20).\n");
        mini_printf("\t'D' Key\tdecrease the speed of the airplanes ");
        mini_printf("(can't go below the original speed).\n");
        return 1;
    }
    return 0;
}
