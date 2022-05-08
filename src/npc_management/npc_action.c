/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** npc_action
*/

#include "prototype.h"
#include "structure.h"

int npc_event(game_t *game, player_t *player)
{
    if (game->current_level != 0)
        return (0);
    for (int i = 0; i < 4; i++) {
        if (get_distance(game->all_npc[i]->pos, player->pos) < 90)
            game->all_npc[i]->is_player_seen = sfTrue;
        else
            game->all_npc[i]->is_player_seen = sfFalse;
    }
    return 0;
}
