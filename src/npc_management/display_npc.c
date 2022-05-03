/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_npc
*/

#include "structure.h"

static int display_npc(game_t *game, npc_t *npc)
{
    char press_space[24] = "Press space to interact";
    sfVector2f text_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {600, 800}, game->view);
    

    if (!npc)
        return 84;
    sfSprite_setPosition(npc->sprite, npc->pos);
    sfRenderWindow_drawSprite(game->window, npc->sprite, NULL);
    if (npc->is_player_seen) {
        sfText_setCharacterSize(game->text, 15);
        sfText_setString(game->text, press_space);
        sfText_setPosition(game->text, text_pos);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    return 0;
}

int display_all_npc(game_t *game)
{
    for (int i = 0; i < 4; i++)
        display_npc(game, game->all_npc[i]);
    return 0;
}
