/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_clothes
*/

#include <stdlib.h>
#include "structure.h"

clothes_t *init_clothes(void)
{
    clothes_t *clothes = malloc(sizeof(clothes_t));

    if (clothes == NULL)
        return NULL;
    clothes->shirt_sprite = NULL;
    clothes->hat_sprite = NULL;
    clothes->pants_sprite = NULL;
    clothes->hat = -1;
    clothes->top = -1;
    clothes->pants = -1;
    clothes->is_gun = sfTrue;
    clothes->swag = 0;
    return clothes;
}

clothes_t *create_start_clothes(game_t *game)
{
    clothes_t *clothes = init_clothes();

    if (clothes == NULL)
        return NULL;
    clothes->pants = BlueGun1;
    clothes->top = TankGun;
    clothes->pants_sprite = game->all_sprite[Pants][clothes->pants];
    clothes->shirt_sprite = game->all_sprite[Shirt][clothes->top];
    return clothes;
}
