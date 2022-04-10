/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** view_destroy
*/

#include <SFML/Graphics.h>
#include "prototype.h"

void destroy_view(game_t *game)
{
    sfView_destroy(game->view);
}
