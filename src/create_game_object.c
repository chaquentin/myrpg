/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_game_object
*/

#include <stdlib.h>
#include "structure.h"
#include "enemies.h"

game_object_t *create_game_object(enum all_sprites sprite, game_t *game)
{
    game_object_t *new_object = NULL;

    new_object = malloc(sizeof(game_object_t));
    if (!new_object)
        return NULL;
    
}