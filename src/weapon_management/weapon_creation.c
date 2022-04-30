/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** weapon_creation
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

int destroy_weapon(weapon_t *weapon)
{
    if (weapon == NULL)
        return 84;
    if (weapon->sound) {
        sfSound_stop(weapon->sound);
        sfSound_destroy(weapon->sound);
    }
    free(weapon);
    return 0;
}

static weapon_t *init_weapon(void)
{
    weapon_t *new_weapon = NULL;

    new_weapon = malloc(sizeof(weapon_t));
    if (new_weapon == NULL)
        return NULL;
    return new_weapon;
}

int change_weapon(player_t *player, game_t *game, enum weapon type)
{
    if (type > 5)
        player->weapon->is_gun = sfFalse;
    else
        player->weapon->is_gun = sfTrue;
    player->weapon->weapon = type;
    player->weapon->damage = (int)gun_damage[type][0];
    player->weapon->ammo = (int)gun_damage[type][1];
    player->weapon->ammo_max = (int)gun_damage[type][1];
    player->weapon->fire_rate = gun_damage[type][2];
    player->weapon->reload_time = gun_damage[type][3];
    player->weapon->sprite = game->all_sprite[Weapon][type];
    update_sprite(player, game);
}

weapon_t *create_start_weapon(game_t *game)
{
    weapon_t *weapon = init_weapon();

    if (!weapon)
        return NULL;
    weapon->weapon = Glock;
    weapon->sprite = game->all_sprite[Weapon][weapon->weapon];
    weapon->is_gun = sfTrue;
    weapon->sound = sfSound_create();
    sfSound_setBuffer(weapon->sound, game->sounds->all_buffer[6]);
    weapon->damage = (int)gun_damage[weapon->weapon][0];
    weapon->ammo = (int)gun_damage[weapon->weapon][1];
    weapon->ammo_max = weapon->ammo;
    weapon->fire_rate = gun_damage[weapon->weapon][2];
    weapon->reload_time = gun_damage[weapon->weapon][3];
    return weapon;
}
