/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** player_creation
*/

#include <stdlib.h>
#include "structure.h"

int *malloc_int(void)
{
    int *array = malloc(sizeof(int) * 4);

    if (array == NULL)
        return (NULL);
    for (int i = 0; i < 4; i++)
        array[i] = 0;
    return (array);
}

player_t *create_player(game_t *game)
{
    player_t *player = NULL;

    player = malloc(sizeof(player_t));
    if (!player)
        return NULL;
    player->health = 5;
    player->is_moving = sfFalse;
    player->pos = (sfVector2f) {928, 508};
    player->speed = 200;
    player->swag = 0;
    player->weapon = NULL;
    player->sprite = game->all_sprite[Nigger1];
    player->clothes_sprite = FlowerShirt1;
    player->clothes = game->all_sprite[FlowerShirt1];
    player->delta_time = 0;
    player->movement = malloc_int();
    player->actual_sprite = Nigger1;
    player->default_sprites = Nigger1;
    if (!player->movement) {
        free(player);
        return NULL;
    }
    return player;
}
