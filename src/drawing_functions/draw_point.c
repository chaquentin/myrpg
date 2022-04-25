/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** draw_point
*/

#include <SFML/Graphics.h>

void draw_point(sfRenderWindow *window, sfVector2f point, sfColor color, int size)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, size);
    sfCircleShape_setOrigin(circle, (sfVector2f){size, size});
    sfCircleShape_setPosition(circle, point);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
    sfCircleShape_destroy(circle);
}
