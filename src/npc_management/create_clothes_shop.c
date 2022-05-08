/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_clothe
*/

#include <stdlib.h>
#include "prototype.h"

int destroy_all_icon_clothes(icon_clothes_t **all_clothes)
{
    for (int i = 0; i < 10; i++) {
        if (all_clothes[i])
            free(all_clothes[i]);
    }
    free(all_clothes);
    return 0;
}

static icon_clothes_t *create_pants(game_t *game, enum pants which_pants,
int owned, int price, int swag)
{
    icon_clothes_t *new_pants = NULL;

    new_pants = malloc(sizeof(clothes_t));
    if (new_pants == NULL)
        return NULL;
    new_pants->sprite = game->all_sprite[Pants][which_pants];
    new_pants->owned = owned;
    new_pants->price = price;
    new_pants->swag = swag;
    return new_pants;
}

static icon_clothes_t *create_hat(game_t *game, enum hat which_hat,
int owned, int price, int swag)
{
    icon_clothes_t *new_hat = NULL;

    new_hat = malloc(sizeof(clothes_t));
    if (new_hat == NULL)
        return NULL;
    new_hat->sprite = game->all_sprite[Hat][which_hat];
    new_hat->owned = owned;
    new_hat->price = price;
    new_hat->swag = swag;
    return new_hat;
}

static icon_clothes_t *create_shirt(game_t *game, enum shirt which_shirt,
int owned, int price, int swag)
{
    icon_clothes_t *new_shirt = NULL;

    new_shirt = malloc(sizeof(clothes_t));
    if (new_shirt == NULL)
        return NULL;
    new_shirt->sprite = game->all_sprite[Shirt][which_shirt];
    new_shirt->owned = owned;
    new_shirt->price = price;
    new_shirt->swag = swag;
    return new_shirt;
}

icon_clothes_t **create_all_icon_clothes(game_t *game)
{
    icon_clothes_t **all_clothes = malloc(sizeof(clothes_t *) * 11);

    all_clothes[0] = create_shirt(game, TankShop, 1, 0, 1);
    all_clothes[1] = create_shirt(game, BlackShop, 0, 15, 5);
    all_clothes[2] = create_shirt(game, FlowerShop, 0, 25, 15);
    all_clothes[3] = create_shirt(game, FireShop, 0, 50, 25);
    all_clothes[4] = create_shirt(game, PinkShop, 0, 85, -40);
    all_clothes[5] = create_hat(game, BlackCapShop, 0, 15, 3);
    all_clothes[6] = create_hat(game, BlackDouragShop, 0, 8, 15);
    all_clothes[7] = create_hat(game, FireCapShop, 0, 25, 20);
    all_clothes[8] = create_pants(game, BluePantsShop, 1, 0, 1);
    all_clothes[9] = create_pants(game, BlackPantsShop, 0, 15, 2);
    all_clothes[10] = NULL;
    return all_clothes;
}
