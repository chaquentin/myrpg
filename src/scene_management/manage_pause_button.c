/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_pause_button
*/

#include <stdlib.h>
#include "prototype.h"

void get_pause_event(game_t *game, sfEvent *event, button_t **all_button)
{
    manage_view_mouse(game, event, all_button);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = Game;
        else if (event->type == sfEvtMouseButtonReleased)
            manage_released(game, all_button);
    }
}

button_t **create_pause_button(game_t *game)
{
    button_t **pause_button = malloc(sizeof(button_t *) * 4);

    pause_button[0] = create_button(Resume1, game, Game);
    pause_button[0]->pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {800, 100}, game->view);
    pause_button[1] = create_button(Menu1, game, Menu);
    pause_button[1]->pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {800, 400}, game->view);
    pause_button[2] = create_button(Exit1, game, Quit);
    pause_button[2]->pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {800, 700}, game->view);
    pause_button[3] = NULL;
    return pause_button;
}

void display_pause_button(button_t **pause_button, game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setScale(pause_button[i]->sprite, (sfVector2f) {2, 2});
        sfSprite_setPosition(pause_button[i]->sprite, pause_button[i]->pos);
        sfRenderWindow_drawSprite(game->window, pause_button[i]->sprite, NULL);
    }
}
