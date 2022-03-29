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
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
}
