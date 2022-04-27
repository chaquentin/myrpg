/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** draw_line
*/

#include <SFML/Graphics.h>
#include "structure.h"

void draw_line(game_t *game, sfVector2f p1, sfVector2f p2,
sfColor color, int thick)
{
    sfConvexShape *convex = sfConvexShape_create();
    sfVector2f p4 = (sfVector2f) {p1.x + thick, p1.y + thick};
    sfVector2f p3 = (sfVector2f) {p2.x + thick, p2.y + thick};

    sfConvexShape_setPointCount(convex, 4);
    sfConvexShape_setPoint(convex, 0, p1);
    sfConvexShape_setPoint(convex, 1, p2);
    sfConvexShape_setPoint(convex, 2, p3);
    sfConvexShape_setPoint(convex, 3, p4);
    sfConvexShape_setFillColor(convex, color);
    sfRenderWindow_drawConvexShape(game->window, convex, NULL);
    sfConvexShape_destroy(convex);
}
