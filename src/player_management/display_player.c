/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_player
*/

#include <stdlib.h>
#include "structure.h"

int update_sprite(player_t *player, game_t *game)
{
    if (player->weapon->is_gun) {
        player->player = PlayerGun1 + (player->player % 4);
        player->clothes->top += (player->clothes->top % 2) ? 0 : 1;
        player->clothes->pants -= (player->clothes->pants % 8 > 3) ? 4 : 0;
    } else {
        player->player = PlayerRifle1 + (player->player % 4);
        player->clothes->top += (player->clothes->top % 2) ? 0 : 1;
        player->clothes->pants += (player->clothes->pants % 8 < 4) ? 4 : 0;
    }
    player->sprite = game->all_sprite[Player][player->player];
    player->clothes->shirt_sprite = game->all_sprite[Shirt][player->clothes->top];
    player->clothes->pants_sprite = game->all_sprite[Pants][player->clothes->pants];
    return 0;
}

static int display_clothe(game_t *game, player_t *player, sfSprite *clothe)
{
    if (!clothe)
        return (84);
    sfSprite_setOrigin(clothe, (sfVector2f) {32, 32});
    sfSprite_setRotation(clothe, sfSprite_getRotation(player->sprite));
    sfSprite_setPosition(clothe, player->pos);
    sfRenderWindow_drawSprite(game->window, clothe, NULL);
    return 0;
}

static int display_weapon(game_t *game, player_t *player)
{
    if (player->weapon->sprite) {
        sfSprite_setOrigin(player->weapon->sprite, (sfVector2f) {32, 32});
        sfSprite_setRotation(player->weapon->sprite,
        sfSprite_getRotation(player->sprite));
        sfSprite_setPosition(player->weapon->sprite, player->pos);
        sfRenderWindow_drawSprite(game->window,
        player->weapon->sprite, NULL);
    }
}

int display_player(game_t *game, player_t *player)
{
    if (!player)
        return 84;
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    display_clothe(game, player, player->clothes->pants_sprite);
    display_clothe(game, player, player->clothes->shirt_sprite);
    display_weapon(game, player);
    display_clothe(game, player, player->clothes->hat_sprite);
    return 0;
}
