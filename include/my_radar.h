/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <stdbool.h>

//info pos
typedef struct pos_s {
    float x;
    float y;
} pos_t;

//info aircraft
typedef struct aircraft_s {
    pos_t *pos;
    pos_t pos_arrival;
    float speed;
    float delay;
    int id;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfInt64 microseconds;
    bool is_active;
    bool is_alive;
} aircraft_t;

typedef struct my_radar_s {
    aircraft_t *data;
    struct my_radar_s *prev;
    struct my_radar_s *next;
} my_radar_t;

typedef struct nbr_aircraft_s {
    my_radar_t *start;
    int cpt;
} nbr_aircraft_t;

//info tower
typedef struct tower_s {
    pos_t *pos_tower;
    float radius;
    int id;
    sfSprite *sprite;
    sfTexture *texture;
} tower_t;

typedef struct my_radar_tower_s {
    tower_t *data_tower;
    struct my_radar_tower_s *next;
} radar_tower_t;

typedef struct nbr_tower_s {
    radar_tower_t *start;
    int cpt;
} nbr_tower_t;

typedef struct simulation_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfSprite *sprite;
    sfTexture *texture;
    int speed_ratio;
    bool pause;
} simulation_t;



//get info
int get_info(char *filepath, nbr_aircraft_t *nbr_aircraft,
    nbr_tower_t *tab_tower);
int add_aircraft(char **individual_info, nbr_aircraft_t *nbr_aircraft);
int add_tower(char **individual_info, nbr_tower_t *tab_tower);
int add_tower(char **individual_info, nbr_tower_t *tab_tower);

//create tool
sfRenderWindow *create_window(void);

//begin simulation
int play_simulation(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower,
    simulation_t *simulation);
int draw_entity(nbr_aircraft_t *nbr_aircraft,
    nbr_tower_t *nbr_tower, simulation_t *simulation, int *is_to_print);
int handle_events(simulation_t *simulation, int *is_to_print,
    int *is_to_print_hitbox);
int move_entity(nbr_aircraft_t *nbr_aircraft, simulation_t *simulation);
float get_direct(my_radar_t *current, int i);
int rotate_sprite(float dx, float dy, my_radar_t *current);
int draw_hitbox(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower,
    simulation_t *simulation, int *is_to_print_hitbox);
int is_active(nbr_aircraft_t *nbr_aircraft, simulation_t *simulation);
int clock_timer(sfClock *timer, int *minute, simulation_t *simulation);
void print(simulation_t *simulation);
int is_h(char *argv1);
nbr_aircraft_t innit_aircraft(void);
nbr_tower_t innit_tower(void);
simulation_t innit_simu(void);

//destroy aircraft
int delete_aircraft(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower);
int delete_colision(nbr_aircraft_t *nbr_aircraft, nbr_tower_t *tab_tower);
int delete_arrival(nbr_aircraft_t *nbr_aircraft);
int is_to_delete(my_radar_t *current,
    nbr_aircraft_t *begin);



#endif /* !MY_RADAR_H_ */
