/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_player
*/

#include "structure.h"
#include "prototype.h"

static int update_level_xp(player_t *player)
{
    if (player->xp > 10 * player->level) {
        player->xp -= 10 * player->level;
        player->level++;
        player->speed += 30;
        player->damage_reduction += 5;
        player->crit_rate += 10;
    }
}

int manage_player(game_t *game, player_t *player)
{
    update_level_xp(player);
    move_player(game, player);
    fill_mouse(game, player);
    return 0;
}
