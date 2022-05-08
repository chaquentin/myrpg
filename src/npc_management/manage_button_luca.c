/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_button_luca
*/

#include <stdio.h>
#include "prototype.h"

void is_select_clothes(game_t *game, player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (game->clothes_shop->all_shop_button[i + 10]->is_click == 1 &&
            game->clothes_shop->all_clothes[i]->owned == 1) {
            choose_clothes(game, player, i);
        }
    }
}

void is_buy_clothes(game_t *game, player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (game->clothes_shop->all_shop_button[i]->is_click == 1 &&
            game->clothes_shop->all_clothes[i]->owned == 0 &&
            game->clothes_shop->all_clothes[i]->price <= player->money) {
            game->clothes_shop->all_clothes[i]->owned = 1;
            player->money -= game->clothes_shop->all_clothes[i]->price;
        }
    }
}

static void set_pos_button(game_t *game)
{
    for (int i = 0; i < 10; i++) {
        game->clothes_shop->all_shop_button[i]->pos =
        sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {875, 40 + i * 97}, game->view);
    }
    for (int i = 10; i < 20; i++) {
        game->clothes_shop->all_shop_button[i]->pos =
        sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {1025, 40 + (i - 10) * 97}, game->view);
    }
}

void display_button_luca(game_t *game, player_t *player)
{
    set_pos_button(game);
    for (int i = 0; i < 10; i++) {
        sfSprite_setPosition(game->clothes_shop->all_shop_button[i]->sprite,
        game->clothes_shop->all_shop_button[i]->pos);
        sfRenderWindow_drawSprite(game->window,
        game->clothes_shop->all_shop_button[i]->sprite, NULL);
    }
    for (int i = 10; i < 20; i++) {
        sfSprite_setPosition(game->clothes_shop->all_shop_button[i]->sprite,
        game->clothes_shop->all_shop_button[i]->pos);
        sfRenderWindow_drawSprite(game->window,
        game->clothes_shop->all_shop_button[i]->sprite, NULL);
    }
}
