/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** antonin_action
*/

#include "prototype.h"

int antonin_action(game_t *game, player_t *player)
{
    sfEvent event;
    int window_open = 1;

    write_dialogue(game, game->all_npc[3]->all_dialogs[0], player);
    return 0;
}
