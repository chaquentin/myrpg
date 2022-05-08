/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** change_level
*/

#include "prototype.h"
#include "structure.h"

int change_level(game_t *game, player_t *player)
{
    sfVector2f down = game->levels[game->current_level]->down;
    sfVector2f up = game->levels[game->current_level]->up;

    if (down.x != -1 && get_distance((sfVector2f) {down.x + 64, down.y + 32},
    player->pos) < 64) {
        player->can_change_level = -1;
    } else if (up.x != -1 && get_distance((sfVector2f) {up.x + 64, up.y + 32},
    player->pos) < 64) {
        player->can_change_level = 1;
    } else
        player->can_change_level = 0;
    return (0);
}
