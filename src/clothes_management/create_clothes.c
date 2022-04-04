/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_clothes
*/

#include <stdlib.h>
#include "structure.h"

int update_clothes(player_t *player, game_t *game, enum clothes new_clothes)
{
    if (new_clothes > 3) {
        player->clothes->head = new_clothes;
        player->clothes->head_sprite = game->all_sprite[21 +
        (player->clothes->head)];
    } else {
        player->clothes->top = new_clothes;
        game->all_sprite[13 +
        ((2 * player->clothes->top) + player->clothes->is_gun)];
    }
    player->swag = (player->clothes->head_sprite) ?
    swag[player->clothes->head] : 0;
    player->swag += swag[player->clothes->top];
    return 0;
}

clothes_t *create_clothes(game_t *game)
{
    clothes_t *clothes = malloc(sizeof(clothes_t));

    if (!clothes)
        return NULL;
    clothes->is_gun = sfTrue;
    clothes->top = TankTopShirt_c;
    clothes->head = 0;
    clothes->head_sprite = NULL;
    clothes->top_sprite = game->all_sprite[13 +
    ((2 * clothes->top) + clothes->is_gun)];
}
