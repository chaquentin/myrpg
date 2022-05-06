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
    int current_weapon = 12;
    sfEvent event;
    sfVector2f pos = {0, 0};
    pos = sfView_getCenter(game->view);
    pos.x -= 3*32;
    pos.y -= 3*32;

    //for (int i = 12; i != 23; i++)
    //    sfSprite_scale(game->all_sprite[Weapon][i], (sfVector2f){3, 3});

    write_dialogue(game, game->all_npc[Matthias - Antonin]->all_dialogs[0]);
    while (window_open) {
        update_clock(game);
        pos.x -= 100 * game->delta_time;
        get_matthias_event(game, player, &event, &window_open);
        if (current_weapon > 22)
            current_weapon = 12;
        sfRenderWindow_clear(game->window, sfBlack);
        sfSprite_setPosition(game->all_sprite[Weapon][current_weapon], pos);
        sfRenderWindow_drawSprite(game->window, game->all_sprite[Weapon][20], NULL);
        current_weapon++;
        printf("%f\n", 100 * game->delta_time);
        sfRenderWindow_display(game->window);
    }
    return (0);
}
