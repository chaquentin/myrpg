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

int destroy_player(game_t *game, player_t *player)
{
    if (player == NULL)
        return (84);
    display_health(game, player, 1);
    display_guns(game, player, 1);
    if (player->weapon != NULL)
        destroy_weapon(player->weapon);
    if (player->clothes != NULL)
        free(player->clothes);
    if (player->movement != NULL)
        free(player->movement);
    free(player);
    return (0);
}

static player_t *init_player(void)
{
    player_t *player = NULL;

    player = malloc(sizeof(player_t));
    if (!player)
        return NULL;
    player->clothes = NULL;
    player->weapon = NULL;
    player->movement = NULL;
    player->speed = 200;
    player->health = 100;
    player->delta_time = 0;
    player->swag = 0;
    player->pos = (sfVector2f) {928, 508};
    player->player = PlayerGun1;
    player->sprite = NULL;
    return player;
}

player_t *create_player(game_t *game)
{
    player_t *player = init_player();

    if (!player)
        return NULL;
    player->sprite = game->all_sprite[Player][player->player];
    player->movement = malloc_int();
    player->weapon = create_start_weapon(game);
    player->clothes = create_start_clothes(game);
    player->is_clicked = sfFalse;
    if (!player->movement || !player->weapon || !player->clothes) {
        destroy_player(game, player);
        return NULL;
    }
    return player;
}
