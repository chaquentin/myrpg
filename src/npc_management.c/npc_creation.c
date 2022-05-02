/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** antonin_management
*/

#include <stdlib.h>
#include "prototype.h"

static char **get_dialogue(char *filepath)
{
    char *buffer = get_file(filepath);
    char **dialogue = NULL;

    if (!buffer)
        return NULL;
    dialogue = my_str_to_word_array(buffer, "&");
    if (!dialogue)
        return NULL;
    free(buffer);
    return dialogue;
}

int destroy_npc(npc_t *npc)
{
    if (!npc)
        return 84;
    if (npc->all_dialogs) {
        for (int i = 0; npc->all_dialogs[i]; i++)
            free(npc->all_dialogs[i]);
        free(npc->all_dialogs);
    }
    free(npc);
    return 0;
}

npc_t *create_npc(game_t *game, enum player which_npc, sfVector2f pos,
char *dialogue_path)
{
    npc_t *new_npc = NULL;

    new_npc = malloc(sizeof(npc_t));
    if (new_npc == NULL)
        return NULL;
    new_npc->sprite = game->all_sprite[Player][which_npc];
    new_npc->pos = pos;
    new_npc->all_dialogs = get_dialogue(dialogue_path);
    return new_npc;
}
