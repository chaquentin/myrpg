/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_player_stats
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static const char *stats[8] = {"Level", "Experience", "Health",
"Critical rate", "Swag", "Damage redution", "Speed", NULL};
static const sfVector2f positions[] = {{500, 100}, {500, 200}, {500, 300},
{500, 400}, {500, 500}, {500, 600}, {-1, -1}};

static int display_int(game_t *game, int to_display, sfVector2f pos)
{
    char *buff = tranform_in_str(to_display);

    sfText_setString(game->text, buff);
    sfText_setPosition(game->text, pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    free(buff);
    return 0;
}

static int get_display_event(game_t *game, sfEvent *event,
int *window_open)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        (event->key.code == sfKeyEscape || event->key.code == sfKeySpace))
            *window_open = 0;
    }
    return (0);
}

static int display_stat(game_t *game, player_t *player)
{
    display_int(game, player->level, positions[0]);
    display_int(game, player->xp, positions[1]);
    display_int(game, player->health, positions[2]);
    display_int(game, player->crit_rate, positions[3]);
    display_int(game, player->swag, positions[4]);
    display_int(game, player->damage_reduction, positions[5]);
    display_int(game, player->speed, positions[6]);
    return (0);
}

int display_player_stats(game_t *game, player_t *player)
{
    int is_open = 1;
    sfEvent event;
    sfVector2f pos = {100, 100};

    sfView_reset(game->view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->view);
    for (int i = 0; stats[i]; i++, pos.y += 100) {
        sfText_setString(game->text, stats[i]);
        sfText_setPosition(game->text, pos);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    display_stat(game, player);
    sfRenderWindow_display(game->window);
    while (is_open) {
        get_display_event(game, &event, &is_open);
        update_clock(game);
    }
    sfView_setSize(game->view, (sfVector2f) {960, 540});
    return 0;
}
