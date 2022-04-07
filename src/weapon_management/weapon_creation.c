/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** weapon_creation
*/

#include <stdlib.h>
#include "structure.h"

int destroy_weapon(weapon_t *weapon)
{
    if (!weapon) 
        return 84;
    if (weapon->sprite)
        sfSprite_destroy(weapon->sprite);
    free(weapon);
    return (0);
}

int update_is_gun(player_t *player, game_t *game)
{
    if (player->clothes->is_gun == sfTrue &&
    player->actual_sprites % 2)
        return (0);
}

weapon_t *create_weapon(enum weapon type, game_t *game)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (!weapon)
        return NULL;
    weapon->ammo = gun_damage[type][0];
    weapon->damage = gun_damage[type][1];
    weapon->reload_time = gun_damage[type][2];
    weapon->fire_rate = gun_damage[type][3];
    weapon->weapon = type + 24;
    weapon->sprite = game->all_sprite[weapon->weapon];
    return (weapon);
}

int update_weapon(player_t *player, game_t *game, enum weapon type)
{
    if (!player->weapon)
        player->weapon = create_weapon(type, game);
    if (!player->weapon)
        return 84;
    player->weapon->ammo = gun_damage[type][0];
    player->weapon->damage = gun_damage[type][1];
    player->weapon->reload_time = gun_damage[type][2];
    player->weapon->fire_rate = gun_damage[type][3];
    player->weapon->weapon = type + 24;
    player->weapon->sprite = game->all_sprite[type + 24];
    if (type < 1)
        player->clothes->is_gun = sfTrue;
    return 0;
}
