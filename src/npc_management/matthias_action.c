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

int show_weapon(game_t *game, sfVector2f pos, int k, float clock)
{
    sfRenderWindow_clear(game->window, sfWhite);
    if (clock < 2) {
        int j = get_randint(12, 22);
        sfSprite_setPosition(game->all_sprite[Weapon][j], pos);
        sfRenderWindow_drawSprite(game->window, game->all_sprite[Weapon]\
        [j], NULL);
    } else {
        sfSprite_setPosition(game->all_sprite[Weapon][k], pos);
        sfRenderWindow_drawSprite(game->window, game->all_sprite[Weapon]\
        [k], NULL);
    }
    sfRenderWindow_display(game->window);
    return (0);
}

int stop_player(player_t *player)
{
    for (int i = 0; i < 4; i++)
        player->movement[i] = 0;
    return (0);
}

sfVector2f my_sfView_getCenter(sfView *view, game_t *game)
{
    sfVector2f pos = sfView_getCenter(game->view);
    pos.x -= 3*32;
    pos.y -= 3*32;
    return (pos);
}


int matthias_action(game_t *game, player_t *player)
{
    int window_open = 1;
    int k = get_randint(12, 22);
    float clock = 0;
    sfEvent event;
    sfVector2f pos = my_sfView_getCenter(game->view, game);

    stop_player(player);
    if (player->money < 50)
        return write_dialogue(game, "Mais tu es pauvre", player);
    if (write_dialogue(game,
    game->all_npc[Matthias - Antonin]->all_dialogs[0], player) == 1)
        return 0;
    player->money -= 50;
    for (int i = 12; i != 23; i++)
        sfSprite_scale(game->all_sprite[Weapon][i], (sfVector2f) {3, 3});
    while (window_open) {
        update_clock(game);
        clock += game->delta_time;
        get_matthias_event(game, player, &event, &window_open);
        show_weapon(game, pos, k, clock);
    }
    for (int i = 12; i != 23; i++)
        sfSprite_scale(game->all_sprite[Weapon][i], (sfVector2f){0.33, 0.33});
    change_weapon(player, game, k - 12);
    return (0);
}
