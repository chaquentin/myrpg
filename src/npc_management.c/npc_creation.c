/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** antonin_management
*/

#include <stdlib.h>
#include "prototype.h"

npc_t *create_npc(game_t *game, enum player which_npc)
{
    npc_t *new_npc = NULL;
    sfVector2f pos = {0, 0};

    new_npc = malloc(sizeof(npc_t));
    if (new_npc == NULL)
        return NULL;
    new_npc->sprite = game->all_sprite[Player][which_npc];
    new_npc->pos = pos;
    new_npc->all_dialogs = NULL;
    return new_npc;
}