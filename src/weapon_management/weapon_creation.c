/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** weapon_creation
*/

#include <stdlib.h>
#include "structure.h"

weapon_t *create_weapon(int nbr_amo, int damage,
enum all_sprites witch_weapon, game_t *game)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (!weapon)
        return NULL;
    weapon->ammo = nbr_amo;
    weapon->damage = damage;
    weapon->weapon = witch_weapon;
    weapon->sprite = game->all_sprite[weapon->weapon];
    return (weapon);
}
