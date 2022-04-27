/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** view_init
*/

#include <SFML/Graphics.h>
#include "structure.h"

sfView *create_view(game_t *game, int debug)
{
    sfView *view = NULL;
    sfVector2f pos = {0, 0};

    if (debug)
        return NULL;
    view = sfView_create();
    sfView_setCenter(view, pos);
    sfView_setSize(view, (sfVector2f) {960, 540});
    sfView_zoom(view, 1);
    return view;
}
