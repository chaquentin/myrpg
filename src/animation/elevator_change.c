/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** elevator_change
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

elevator_t *black_fade(game_t *game, elevator_t *e)
{
    sfRectangleShape *rectangle = rectangle = sfRectangleShape_create();
    sfRectangleShape_setOrigin(rectangle, (sfVector2f) {1920, 1080});
    sfRectangleShape_setSize(rectangle, (sfVector2f) {3840, 2160});
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {960, 540});
    for (float i = 0; i < 2.56; i += game->delta_time) {
        sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, i * 10});
        sfRenderWindow_drawRectangleShape(game->window, rectangle, NULL);
        sfRenderWindow_display(game->window);
    }
    for (float i = 2.56; i > 0; i -= game->delta_time) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window,
        game->levels[game->current_level]->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, e->elevator, NULL);
        sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, i * 100});
        sfRenderWindow_drawRectangleShape(game->window, rectangle, NULL);
        sfRenderWindow_display(game->window);
    }
    sfRectangleShape_destroy(rectangle);
    return e;
}

int elevator_up(game_t *game, elevator_t *e)
{
    float duration = 5;

    while (duration > 0) {
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        update_clock(game);
        duration -= game->delta_time;
        sfRenderWindow_drawSprite(game->window, e->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, e->elevator, NULL);
        sfSprite_scale(e->sprite, (sfVector2f) {1 - (game->delta_time / 10),
        1 - (game->delta_time / 10)});
        sfSprite_scale(e->elevator, (sfVector2f) {1 + (game->delta_time / 5),
        1 + (game->delta_time / 5)});
    }
}

int elevator_down(game_t *game, elevator_t *e)
{
    float duration = 5;

    while (duration > 0) {
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        update_clock(game);
        duration -= game->delta_time;
        sfRenderWindow_drawSprite(game->window, e->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, e->elevator, NULL);
        sfSprite_scale(e->sprite, (sfVector2f) {1 + (game->delta_time / 10),
        1 + ((game->delta_time) / 10)});
        sfSprite_scale(e->elevator, (sfVector2f) {1 - (game->delta_time / 5),
        1 - ((game->delta_time) / 5)});
    }
}

elevator_t *elevator_init(game_t *game, int direction)
{
    elevator_t *e = malloc(sizeof(elevator_t));
    int index = (direction == 1) ? 0 : 1;

    e->pos = game->levels[game->current_level - index]->up;
    e->pos = (sfVector2f) {e->pos.x + (64 * 0.9375), e->pos.y + (64 * 0.9375)};
    e->sprite = sfSprite_copy(game->levels[game->current_level -
    index]->sprite);
    e->elevator = sfSprite_copy(game->all_sprite[Decor][Elevator]);
    sfSprite_setOrigin(e->sprite, e->pos);
    sfSprite_setOrigin(e->elevator, (sfVector2f) {(512 / 2), (475)});
    sfSprite_setPosition(e->elevator, (sfVector2f) {e->pos.x, e->pos.y -
    (64 * 0.9375)});
    sfSprite_setPosition(e->sprite, e->pos);
    sfRenderWindow_display(game->window);
    sfView_setCenter(game->view, (sfVector2f) {e->pos.x, e->pos.y -
    (64 * 0.9375 * 3)});
    sfRenderWindow_setView(game->window, game->view);
    return e;
}

int elevator_change(game_t *game, int direction)
{
    elevator_t *e = elevator_init(game, direction);

    sfRenderWindow_display(game->window);
    if (direction == 1) {
        sfSprite_setScale(e->elevator, (sfVector2f) {0.23, 0.23});
        black_fade(game, e);
        elevator_up(game, e);
    }
    if (direction == -1) {
        sfSprite_scale(e->sprite, (sfVector2f) {0.58, 0.58});
        sfSprite_scale(e->elevator, (sfVector2f) {0.8, 0.8});
        black_fade(game, e);
        elevator_down(game, e);
    }
    sfSprite_destroy(e->sprite);
    sfSprite_destroy(e->elevator);
    free(e);
    return direction;
}
