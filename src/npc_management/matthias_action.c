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

int show_weapon(game_t *game, player_t *player)
{
    sfVector2f pos = sfView_getCenter(game->view);
    while (1) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfSprite_setPosition(game->all_sprite[Weapon][20], pos);
        sfRenderWindow_drawSprite(game->window, game->all_sprite[Weapon][20], NULL);
    }
    return (0);
}

int matthias_action(game_t *game, player_t *player)
{
    int window_open = 1;
    int current_weapon = 12;
    sfEvent event;
    sfVector2f pos = {0, 0};
    float clock = 0;
    pos = sfView_getCenter(game->view);
            sfClock *cock;
    pos.x -= 3*32;
    pos.y -= 3*32;

    int speed = 2000;

    int k = get_randint(12, 22);

    for (int i = 12; i != 23; i++)
        sfSprite_scale(game->all_sprite[Weapon][i], (sfVector2f){3, 3});

    write_dialogue(game, game->all_npc[Matthias - Antonin]->all_dialogs[0]);


    while (window_open) {
        update_clock(game);
        clock += game->delta_time;
        sfRenderWindow_clear(game->window, sfWhite);
        get_matthias_event(game, player, &event, &window_open);
        if (clock < 2) {
            int j = get_randint(12, 22);
            sfSprite_setPosition(game->all_sprite[Weapon][j], pos);
            sfRenderWindow_drawSprite(game->window, game->all_sprite[Weapon][j], NULL);
        }
        else {
            sfSprite_setPosition(game->all_sprite[Weapon][k], pos);
            sfRenderWindow_drawSprite(game->window, game->all_sprite[Weapon][k], NULL);
        }
        sfRenderWindow_display(game->window);
    }
    for (int i = 12; i != 23; i++)
        sfSprite_scale(game->all_sprite[Weapon][i], (sfVector2f){0.333, 0.333});
    change_weapon(player, game, k - 12);
    return (0);
}
