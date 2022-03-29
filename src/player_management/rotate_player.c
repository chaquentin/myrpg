/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** rotate_player
*/

#include <math.h>
#include "structure.h"

void fill_mouse(game_t *game, player_t *player)
{
    sfVector2i get_mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_pos;
    float rotation = 0.0;

    mouse_pos.x = (float)get_mouse_pos.x - player->pos.x;
    mouse_pos.y = (float)get_mouse_pos.y - player->pos.y;
    rotation = atan(mouse_pos.x / mouse_pos.y) * (180.0/PI) * -1;
    sfSprite_setOrigin(player->sprite, (sfVector2f) {32, 32});
    sfSprite_setRotation(player->sprite, rotation);
}
