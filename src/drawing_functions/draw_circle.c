/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** draw_circle
*/

#include <SFML/Graphics.h>

void draw_circle(sfRenderWindow *window, sfVector2f pos, float radius, sfColor color)
{      
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOutlineColor(circle, color);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setRadius(circle, radius);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
    sfCircleShape_destroy(circle);
}
