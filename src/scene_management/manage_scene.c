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
    destroy_button(all_pause_button);
    return 0;
}

static int get_win_event(game_t *game, sfEvent *event, int *window_open)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
            *window_open = 0;
    }
}

int win(game_t *game, player_t *player, sfEvent event)
{
    int window_open = 1;
    sfEvent event_win;
    sprite_t *win_sprite = create_sprite("asset/win.jpg");

    sfSprite_setScale(win_sprite->sprite, (sfVector2f) {3.1, 3.1});
    sfView_reset(game->view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->window, game->view);
    while (window_open) {
        get_win_event(game, &event_win, &window_open);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, win_sprite->sprite, NULL);
        sfText_setFont(game->text, game->font);
        sfText_setString(game->text, "Merci bebou, j'ai cru que j'allais\
        encore rater le brevet ! <3\n Press Escape to exit");
        sfText_setPosition(game->text, (sfVector2f) {400, 540});
        sfRenderWindow_drawText(game->window, game->text, NULL);
        sfRenderWindow_display(game->window);
    }
    destroy_sprite(win_sprite);
    game->scene = Quit;
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

    destroy_player(game, player);
    return 0;
}
