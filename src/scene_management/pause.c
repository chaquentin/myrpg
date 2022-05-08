/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** pause
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

int do_pause(game_t *game, player_t *player, sfEvent event)
{
    button_t **all_pause_button = create_pause_button(game);

    while (game->scene == Pause) {
        update_clock(game);
        get_pause_event(game, &event, all_pause_button);
        display_pause_button(all_pause_button, game);
        sfRenderWindow_display(game->window);
    }
    if (game->scene == Menu) {
        sfView_reset(game->view, (sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(game->window, game->view);
    }
    return 0;
}
