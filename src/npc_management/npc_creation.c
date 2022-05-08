/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** antonin_management
*/

#include <stdlib.h>
#include "prototype.h"

static const int (*all_action[4])(game_t *game, player_t *player) = {antonin_action,
matthias_action, quentin_action, luca_action};

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

static int destroy_npc(npc_t *npc)
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

int destroy_all_npc(npc_t **npc)
{
    if (!npc)
        return 84;
    for (int i = 0; i < 4; i++)
        destroy_npc(npc[i]);
    free(npc);
    return 0;
}

static npc_t *create_npc(game_t *game, enum player which_npc, sfVector2f pos,
char *dialogue_path)
{
    npc_t *new_npc = NULL;

    new_npc = malloc(sizeof(npc_t));
    if (new_npc == NULL)
        return NULL;
    new_npc->sprite = game->all_sprite[Player][which_npc];
    new_npc->pos = pos;
    new_npc->all_dialogs = get_dialogue(dialogue_path);
    new_npc->is_player_seen = sfFalse;
    new_npc->is_slected = sfFalse;
    new_npc->action = all_action[which_npc - Antonin];
    return new_npc;
}

npc_t **create_all_npc(game_t *game)
{
    npc_t **all_npc = malloc(sizeof(npc_t *) * 4);

    all_npc[0] = create_npc(game, Luca, (sfVector2f) {1450, 740},
    "asset/npc_dialogue/luca.txt");
    all_npc[1] = create_npc(game, Matthias, (sfVector2f) {1800, 980},
    "asset/npc_dialogue/mathias.txt");
    all_npc[2] = create_npc(game, Quentin, (sfVector2f) {600, 40},
    "asset/npc_dialogue/quentin.txt");
    all_npc[3] = create_npc(game, Antonin, (sfVector2f) {850, 780},
    "asset/npc_dialogue/antonin.txt");
    for (int i = 0; i < 4; i++)
        if (!all_npc[i]) {
            destroy_all_npc(all_npc);
            return NULL;
        }
    return all_npc;
}
