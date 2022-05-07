/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** matthias_action
*/

#include <stdio.h>
#include "prototype.h"

static int get_matthias_event(game_t *game, player_t *player, sfEvent *event,
int *window_open)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        event->key.code == sfKeyEscape)
            *window_open = 0;
    }
    return (0);
}

int matthias_action(game_t *game, player_t *player)
{
    int window_open = 1;
    sfEvent event;

    write_dialogue(game, game->all_npc[Matthias - Antonin]->all_dialogs[0]);
    while (window_open) {
        update_clock(game);
        get_matthias_event(game, player, &event, &window_open);
        sfRenderWindow_clear(game->window, sfBlue);
        sfRenderWindow_display(game->window);
    }
    for (int i = 0; i < 4; i++)
        player->movement[i] = 0;
    return (0);
}
