/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_player
*/

#include <stdlib.h>
#include "structure.h"

static int display_clothes(game_t *game, player_t *player)
{
    if (player->clothes->head_sprite) {
        sfSprite_setOrigin(player->clothes->head_sprite, (sfVector2f){32, 32});
        sfSprite_setRotation(player->clothes->head_sprite,
        sfSprite_getRotation(player->sprite));
        sfSprite_setPosition(player->clothes->head_sprite, player->pos);
        sfRenderWindow_drawSprite(game->window,
        player->clothes->head_sprite, NULL);
    }
    sfSprite_setOrigin(player->clothes->top_sprite, (sfVector2f){32, 32});
    sfSprite_setRotation(player->clothes->top_sprite,
    sfSprite_getRotation(player->sprite));
    sfSprite_setPosition(player->clothes->top_sprite, player->pos);
    sfRenderWindow_drawSprite(game->window,
    player->clothes->top_sprite, NULL);
}

static int display_weapon(game_t *game, player_t *player)
{
    if (player->weapon->sprite) {
        sfSprite_setOrigin(player->weapon->sprite, (sfVector2f){32, 32});
        sfSprite_setRotation(player->weapon->sprite,
        sfSprite_getRotation(player->sprite));
        sfSprite_setPosition(player->weapon->sprite, player->pos);
        sfRenderWindow_drawSprite(game->window,
        player->weapon->sprite, NULL);
    }
}

void display_player(game_t *game, player_t *player)
{
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    display_clothes(game, player);
    display_weapon(game, player);
}
