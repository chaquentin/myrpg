/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** start_game
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static void get_event(game_t *game, sfEvent *event, player_t *player)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed)
            manage_key_pressed(game, event->key.code, player);
        if (event->type == sfEvtKeyReleased)
            manage_key_released(event->key.code, player);
    }
}

int update_clock(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;
    static float old_seconds = 0.0;

    game->delta_time = seconds - old_seconds;
    old_seconds = seconds;
    if (seconds > 10) {
        sfClock_restart(game->clock);
        old_seconds = 0.0;
    }
    return (0);
}

int display(game_t *game, player_t *player)
{
    display_map_sprite(game);
    display_enemies(game);
    display_player(game, player);
    sfRenderWindow_display(game->window);
    return 0;
}

int game(game_t *game, player_t *player, sfEvent event)
{
    update_clock(game);
    view_update(game, player);
    sfRenderWindow_clear(game->window, sfBlack);
    get_event(game, &event, player);
    move_player(game, player);
    enemy_actions(game, player);
    fill_mouse(game, player);
    display(game, player);
    return 0;
}
