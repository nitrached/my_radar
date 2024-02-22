/*
** EPITECH PROJECT, 2023
** draw circle
** File description:
** sraw a circle with csfml
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};

    return sfRenderWindow_create(mode, "my radar", sfResize | sfClose, NULL);
}

int handle_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return 0;
}

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f posc1 = sfCircleShape_getPosition(c1);
    sfVector2f posc2 = sfCircleShape_getPosition(c2);

    posc1.x = posc1.x + sfCircleShape_getRadius(c1);
    posc1.y = posc1.y + sfCircleShape_getRadius(c1);
    posc2.x = posc2.x + sfCircleShape_getRadius(c2);
    posc2.y = posc2.y + sfCircleShape_getRadius(c2);
    if ((pow(posc1.x - posc2.x, 2) + pow(posc1.y - posc2.y, 2)) <= pow(sfCircleShape_getRadius(c1) + sfCircleShape_getRadius(c2), 2))
        return 1;
    return 0;
}

sfCircleShape **generate_circle(void)
{
    sfCircleShape **circle = malloc(sizeof(sfCircleShape *) * (30 + 1));
    int x = 0;
    int y = 0;
    int rad = 20;

    for (int i = 0; i < 30; i++) {
        x = (rand() % 1820);
        y = (rand() % 1000);
        circle[i] = sfCircleShape_create();
        sfCircleShape_setPosition(circle[i], (sfVector2f){x, y});
        sfCircleShape_setRadius(circle[i], rad);
        sfCircleShape_setFillColor(circle[i], sfTransparent);
        sfCircleShape_setOutlineColor(circle[i], sfWhite);
        sfCircleShape_setOutlineThickness(circle[i], 1.0);
    }
    return circle;
}

int create_circle(void)
{
    sfRenderWindow *window = create_window();
    sfCircleShape **circle = generate_circle();
    int p = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        for (int i = 0; i < 30; i++) {
            for (int y = 0; y < 30; y++) {
                if (i == y)
                    continue;
                p = is_intersecting_circles(circle[i], circle[y]);
                if (p == 1) {
                    sfCircleShape_setFillColor(circle[i], sfWhite);
                    sfCircleShape_setFillColor(circle[y], sfWhite);
                } else {
                    sfCircleShape_setFillColor(circle[y], sfTransparent);
                }
            }
            sfRenderWindow_drawCircleShape(window, circle[i], NULL);
        }
        handle_events(window);
        sfRenderWindow_display(window);
    }
    return 0;
}
