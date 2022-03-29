/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** player_creation
*/

#include <stdlib.h>
#include "structure.h"

player_t *create_player(game_t *game)
{
    player_t *player = NULL;

    player = malloc(sizeof(player_t));
    if (!player)
        return NULL;
    player->health = 5;
    player->is_moving = sfFalse;
    player->pos = (sfVector2f){928, 508};
    player->speed = 2;
    player->swag = 0;
    player->weapon = NULL;
    player->sprite = game->all_sprite[Nigger1];
    return player;
}
