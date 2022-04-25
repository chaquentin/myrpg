/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_button
*/

#include "structure.h"

button_t* create_button(enum button type, game_t *game,
enum game_scene next_scene)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->status = type;
    button->sprite = game->all_sprite[Button][type];
    button->next_scene = next_scene;
    return button;
}
