/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_scene
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

int pause(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL);
    return 0;
}

int win(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL);
    return 0;
}

static const int (*game_function[])(game_t *, player_t *, sfEvent) = {&menu,
&game, &option, &pause, &win, &help};

int manage_scene(game_t *game)
{
    int error_code = 0;
    player_t *player = NULL;
    sfEvent event;

    player = create_player(game);
    if (!player)
        return 84;
    while (game->scene != Quit) {
        error_code = game_function[game->scene - 1](game, player, event);
    }
    destroy_player(player);
    return 0;
}
