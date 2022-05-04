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
    sfConvexShape *convex1 = sfConvexShape_create();
    sfConvexShape *convex2 = sfConvexShape_create();

    sfConvexShape_setPointCount(convex1, 4);
    sfConvexShape_setPointCount(convex2, 4);
    sfConvexShape_setPoint(convex1, 0, (sfVector2f) {p1.x - thick, p1.y});
    sfConvexShape_setPoint(convex1, 1, (sfVector2f) {p2.x - thick, p2.y});
    sfConvexShape_setPoint(convex1, 3, (sfVector2f) {p1.x + thick, p1.y});
    sfConvexShape_setPoint(convex1, 2, (sfVector2f) {p2.x + thick, p2.y});
    sfConvexShape_setPoint(convex2, 0, (sfVector2f) {p1.x, p1.y + thick});
    sfConvexShape_setPoint(convex2, 1, (sfVector2f) {p2.x, p2.y + thick});
    sfConvexShape_setPoint(convex2, 3, (sfVector2f) {p1.x, p1.y - thick});
    sfConvexShape_setPoint(convex2, 2, (sfVector2f) {p2.x, p2.y - thick});
    sfConvexShape_setFillColor(convex1, color);
    sfConvexShape_setFillColor(convex2, color);
    sfRenderWindow_drawConvexShape(game->window, convex1, NULL);
    sfRenderWindow_drawConvexShape(game->window, convex2, NULL);
    sfConvexShape_destroy(convex1);
    sfConvexShape_destroy(convex2);
}
