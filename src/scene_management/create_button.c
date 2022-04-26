/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_button
*/

#include <stdlib.h>
#include "structure.h"

int display_button(button_t **button, game_t *game)
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {2, 2};

    for (int i = 0; button[i]; i++) {
        scale.x = 3;
        scale.y = 3;
        pos = button[i]->pos;
        sfSprite_setScale(button[i]->sprite, scale);
        sfSprite_setPosition(button[i]->sprite, pos);
        sfRenderWindow_drawSprite(game->window, button[i]->sprite, NULL);
        scale.x = 1;
        scale.y = 1;
        sfSprite_setScale(button[i]->sprite, scale);
    }
}

int destroy_button(button_t **button)
{
    if (!button)
        return 84;
    for (int i = 0; button[i]; i++)
        free(button[i]);
    free(button);
    return 0;
}

button_t *create_button(enum button type, game_t *game,
enum game_scene next_scene)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->status = type;
    button->sprite = game->all_sprite[Button][type];
    button->next_scene = next_scene;
    button->pos = (sfVector2f) {0, 0};
    return button;
}
