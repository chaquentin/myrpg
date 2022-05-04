/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** draw_framebuffer
*/

#include <SFML/Graphics.h>
#include "structure.h"

void draw_framebuffer(game_t *game)
{
    sfTexture *tex = sfTexture_create(game->framebuffer->width,
        game->framebuffer->height);
    sfSprite *sprite = sfSprite_create();

    sfTexture_updateFromPixels(tex, game->framebuffer->pixels,
        game->framebuffer->width, game->framebuffer->height, 0, 0);
    sfSprite_setTexture(sprite, tex, sfTrue);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(tex);
    return;
}
