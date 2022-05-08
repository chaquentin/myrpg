/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_player_stats
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static int get_display_event(game_t *game, sfEvent *event, player_t *player,
button_t **button)
{
    int ret_value = 1;

    manage_mouse(game, event, button);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        (event->key.code == sfKeyEscape || event->key.code == sfKeyE))
            ret_value = 0;
        if (event->type == sfEvtMouseButtonReleased)
            use_drug(game, player, button);
    }
    return (ret_value);
}

static button_t **create_invent_button(game_t *game)
{
    button_t **button = malloc(sizeof(button_t *) * 4);
    sfVector2f pos = {1038, 690};

    button[0] = create_button(Select1, game, Game);
    button[0]->pos = pos;
    button[1] = create_button(Select1, game, Game);
    button[1]->pos = (sfVector2f) {pos.x + 160, pos.y};
    button[2] = create_button(Select1, game, Game);
    button[2]->pos = (sfVector2f) {pos.x + 320, pos.y};
    button[3] = NULL;
    return (button);
}

static int display_stats_button(game_t *game, button_t **button)
{
    for (int i = 0; button[i]; i++) {
        sfSprite_setPosition(button[i]->sprite, button[i]->pos);
        sfRenderWindow_drawSprite(game->window, button[i]->sprite, NULL);
    }
    sfRenderWindow_display(game->window);
    return 0;
}

int display_player_stats(game_t *game, player_t *player)
{
    int is_open = 1;
    sfEvent event;
    button_t **button = create_invent_button(game);

    sfView_reset(game->view, (sfFloatRect) {0, 0, 1920, 1080});
    while (is_open) {
        display_stat(game, player);
        is_open = get_display_event(game, &event, player, button);
        display_stats_button(game, button);
        update_clock(game);
    }
    for (int i = 0; i < 4; i++)
        player->movement[i] = 0;
    sfView_setSize(game->view, (sfVector2f) {960, 540});
    destroy_button(button);
    return 0;
}
