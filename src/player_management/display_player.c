/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_player
*/

#include <stdlib.h>
#include "structure.h"

void display_player(game_t *game, player_t *player)
{
    player->clothes = game->all_sprite[player->clothes_sprite + (player->actual_sprite - player->default_sprites)];
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setPosition(player->clothes, player->pos);
    sfSprite_setOrigin(player->clothes, (sfVector2f) {32, 32});
    sfSprite_setRotation(player->clothes, sfSprite_getRotation(player->sprite));
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, player->clothes, NULL);
}
