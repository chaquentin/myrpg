/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_button_clothes_shop
*/

#include <stdlib.h>
#include "prototype.h"

button_t **create_button_clothes_shop(game_t *game)
{
    button_t **all_button = malloc(sizeof(button_t *) * 21);

    for (int i = 0; i < 10; i++) {
        all_button[i] = create_button(Buy1, game, Game);
        all_button[i]->pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {1010, 150 + i * 50}, game->view);
    }
    for (int i = 10; i < 20; i++) {
        all_button[i] = create_button(Select1, game, Game);
        all_button[i]->pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {1085, 150 + i * 50}, game->view);
    }
    all_button[20] = NULL;
    return all_button;
}
