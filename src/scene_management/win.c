/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** win
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

static int get_win_event(game_t *game, sfEvent *event, int *window_open)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
            *window_open = 0;
    }
}

static int end_window(game_t *game, sprite_t *win_sprite)
{
    destroy_sprite(win_sprite);
    game->scene = Quit;
    return 0;
}

int win(game_t *game, player_t *player, sfEvent event)
{
    int window_open = 1;
    sfEvent event_win;
    sprite_t *win_sprite = create_sprite("asset/win.jpg");

    sfSprite_setScale(win_sprite->sprite, (sfVector2f) {3.1, 3.1});
    sfView_reset(game->view, (sfFloatRect) {0, 0, 1920, 1080});
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
    return end_window(game, win_sprite);
}
