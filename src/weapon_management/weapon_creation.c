/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** weapon_creation
*/

#include <stdlib.h>
#include "structure.h"

static weapon_t *init_weapon(void)
{
    weapon_t *new_weapon = NULL;

    new_weapon = malloc(sizeof(weapon_t));
    if (new_weapon == NULL)
        return NULL;
    new_weapon->sprite = NULL;
    new_weapon->is_gun = sfTrue;
    new_weapon->weapon = -1;
    new_weapon->damage = 0;
    new_weapon->ammo = 0;
    new_weapon->reload_time = 0.0;
    new_weapon->fire_rate = 0.0;
    return new_weapon;
}

weapon_t *create_start_weapon(game_t *game)
{
    weapon_t *weapon = init_weapon();

    if (!weapon)
        return NULL;
    weapon->weapon = Gun;
    weapon->sprite = game->all_sprite[Weapon][weapon->weapon];
    weapon->is_gun = sfTrue;
    weapon->damage = gun_damage[weapon->weapon][0];
    weapon->ammo = gun_damage[weapon->weapon][1];
    weapon->fire_rate = gun_damage[weapon->weapon][2];
    weapon->reload_time = gun_damage[weapon->weapon][3];
    return weapon;
}
