/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** start_game
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

void get_event(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) {
            sfRenderWindow_close(game->window);
        }
    }
}

int start_game(game_t *game, player_t *player)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        get_event(game, &event);
        fill_mouse(game, player);
        display_player(game, player);
        sfRenderWindow_display(game->window);
    }
}
