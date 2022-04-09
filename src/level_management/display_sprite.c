/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_sprite
*/

#include <SFML/Graphics.h>
#include "level.h"
#include "structure.h"
#include "prototype.h"

void display_map_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->levels[game->current_level]->sprite, NULL);
}
