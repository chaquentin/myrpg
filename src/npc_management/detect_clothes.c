/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** detect_clothes
*/

#include "prototype.h"

static void equip_pants(game_t *game, player_t *player, int i)
{
    if (player->clothes->is_gun) {
        if (i == 0) {
            player->clothes->pants_sprite = game->all_sprite[Pants][0];
            player->clothes->pants = 0;
        } else {
            player->clothes->pants_sprite = game->all_sprite[Pants][8];
            player->clothes->pants = 8;
        }
    } else {
        if (i == 0) {
            player->clothes->pants_sprite = game->all_sprite[Pants][4];
            player->clothes->pants = 4;
        } else {
            player->clothes->pants_sprite = game->all_sprite[Pants][12];
            player->clothes->pants = 12;
        }
    }
}

static void equip_hat(game_t *game, player_t *player, int i)
{
    player->clothes->hat_sprite = game->all_sprite[Hat][i];
    player->clothes->hat = i;
}

static void equip_shirt(game_t *game, player_t *player, int i)
{
    int id_shirt = 0;

    for (int j = 0; j < i; j++)
        id_shirt += 2;
    if (player->clothes->is_gun) {
        player->clothes->shirt_sprite = game->all_sprite[Shirt][id_shirt];
        player->clothes->top = id_shirt;
    } else {
        player->clothes->shirt_sprite = game->all_sprite[Shirt][id_shirt + 1];
        player->clothes->top = id_shirt + 1;
    }
}

void choose_clothes(game_t *game, player_t *player, int i)
{
    if (i < 5) {
        equip_shirt(game, player, i);
    } else if (i < 8) {
        equip_hat(game, player, i - 5);
    } else {
        equip_pants(game, player, i - 8);
    }
}
