/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** particle_types
*/

#include <SFML/Graphics.h>
#include "structure.h"
#include "prototype.h"
#include "enemies.h"

int particle(game_t *game, enum particle_type type, sfVector2f pos)
{
    switch (type) {
        case Blood:
            particle_append(game->particle, pos,
            (sfColor) {255, 0, 0, 100}, 0.45);
            break;
        case Steps:
            particle_append(game->particle, pos,
            (sfColor) {100, 50, 0, 75}, 0.045);
            break;
        default:
            break;
    }
    return 0;
}
