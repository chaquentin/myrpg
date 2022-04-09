/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** view_update
*/

#include <SFML/Graphics.h>
#include "structure.h"

void view_update(game_t *game, player_t *player)
{
    if (game->view) {
        sfView_setCenter(game->view, player->pos);
        sfRenderWindow_setView(game->window, game->view);
    }
}
