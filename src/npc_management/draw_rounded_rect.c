/*
** EPITECH PROJECT, 2022
** bordel
** File description:
** draw_rounded_rect
*/

#include "structure.h"

static void set_shape(sfRectangleShape **rect, sfCircleShape **circle,
sfVector2f *pos, game_t *game)
{
    for (int i = 0; i < 4; i++) {
        sfCircleShape_setPosition(*circle, pos[i]);
        sfRenderWindow_drawCircleShape(game->window, *circle, NULL);
    }
    for (int i = 0; i < 2; i++) {
        sfRectangleShape_setPosition(*rect, pos[4 + i * 2]);
        sfRectangleShape_setSize(*rect, pos[5 + i * 2]);
        sfRenderWindow_drawRectangleShape(game->window, *rect, NULL);
    }
}

void draw_rounded_rectangle(game_t *game, sfIntRect d, float r,
sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos[8] = {{d.left, d.top}, {d.left + d.width - r * 2, d.top},
    {d.left + d.width - r * 2, d.top + d.height - 2 * r}, {d.left,
    d.top + d.height - 2 * r}, {d.left, d.top + r}, {d.width, d.height - 2 * r}
    , {d.left + r, d.top}, {d.width - 2 * r, d.height}};

    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, r);
    sfRectangleShape_setFillColor(rect, color);
    set_shape(&rect, &circle, pos, game);
    sfRectangleShape_destroy(rect);
    sfCircleShape_destroy(circle);
}
