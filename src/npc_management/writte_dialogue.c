/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** writte_dialogue
*/

#include "structure.h"

static int get_dialogue_event(game_t *game, sfEvent *event,
int *window_open)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        (event->key.code == sfKeyEscape || event->key.code == sfKeySpace))
            *window_open = 0;
    }
    return (0);
}

int write_dialogue(game_t *game, char *dialogue)
{
    int window_open = 1;
    sfEvent event;
    sfVector2f text_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {600, 800}, game->view);

    sfText_setString(game->text, dialogue);
    sfText_setCharacterSize(game->text, 15);
    sfText_setPosition(game->text, text_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfRenderWindow_display(game->window);
    while (window_open)
        get_dialogue_event(game, &event, &window_open);
    return (0);
}
