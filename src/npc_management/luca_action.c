/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** luca_action
*/

#include <stdio.h>
#include "prototype.h"

static int get_luca_event(game_t *game, player_t *player, sfEvent *event,
int *window_open)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        event->key.code == sfKeyEscape)
            *window_open = 0;
    }
    return (0);
}

int luca_action(game_t *game, player_t *player)
{
    int window_open = 1;
    sfEvent event;

    while (window_open) {
        get_luca_event(game, player, &event, &window_open);
        sfRenderWindow_clear(game->window, sfBlue);
        sfRenderWindow_display(game->window);
    }
    return (0);
}
