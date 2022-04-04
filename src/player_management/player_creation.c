/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** player_creation
*/

#include <stdlib.h>
#include "prototype.h"
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

int destroy_player(player_t *player)
{
    if (player == NULL)
        return (84);
    if (player->weapon != NULL)
        free(player->weapon);
    if (player->clothes != NULL)
        free(player->clothes);
    if (player->movement != NULL)
        free(player->movement);
    free(player);
    return (0);
}

int add_default_param(player_t *player, game_t *game)
{
    player->speed = 200;
    player->health = 100;
    player->delta_time = 0;
    player->swag = 0;
    player->pos = (sfVector2f) {928, 508};
    player->actual_sprites = NiggerGun;
    player->sprite = game->all_sprite[player->actual_sprites];
    return 0;
}

player_t *create_player(game_t *game)
{
    player_t *player = NULL;

    player = malloc(sizeof(player_t));
    if (!player)
        return NULL;
    player->weapon = NULL;
    player->clothes = NULL;
    player->movement = malloc_int();
    player->weapon = create_weapon(9, 53, Gun, game);
    player->clothes = create_clothes(game);
    if (!player->movement || !player->weapon || !player->clothes) {
        destroy_player(player);
        return NULL;
    }
    add_default_param(player, game);
    return player;
}
