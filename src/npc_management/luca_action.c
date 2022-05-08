/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** luca_action
*/

#include <stdio.h>
#include "prototype.h"

static void display_luca_shop(game_t *game, player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite);

    sfSprite_setOrigin(game->all_sprite[Decor][ClothesShop],
    (sfVector2f) {96, 192});
    sfSprite_setScale(game->all_sprite[Decor][ClothesShop],
    (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->all_sprite[Decor][ClothesShop], pos);
    sfRenderWindow_drawSprite(game->window, game->all_sprite[Decor]
    [ClothesShop], NULL);
}

static void dipslay_clothe(sfSprite *clothe, game_t *game, sfVector2f pos)
{
    sfSprite_setOrigin(clothe, (sfVector2f) {32, 32});
    sfSprite_setScale(clothe, (sfVector2f) {0.65, 0.65});
    sfSprite_setPosition(clothe, pos);
    sfRenderWindow_drawSprite(game->window, clothe, NULL);
}

static void display_all_clothes(game_t *game, player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite);

    pos.y -= 220;
    pos.x -= 80;
    for (int i = 10; i < 15; i++) {
        dipslay_clothe(game->all_sprite[Shirt][i], game, pos);
        pos.y += 48;
    }
    for (int i = 3; i < 6; i++) {
        dipslay_clothe(game->all_sprite[Hat][i], game, pos);
        pos.y += 48;
    }
    for (int i = 16; i < 18; i++) {
        dipslay_clothe(game->all_sprite[Pants][i], game, pos);
        pos.y += 48;
    }
}

static int get_luca_event(game_t *game, player_t *player, sfEvent *event,
int *window_open)
{
    manage_view_mouse(game, event, game->clothes_shop->all_shop_button);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        event->key.code == sfKeyEscape)
            *window_open = 0;
        if (event->type == sfEvtMouseButtonReleased) {
            is_buy_clothes(game, player);
            is_select_clothes(game, player);
        }
    }
    return (0);
}

int luca_action(game_t *game, player_t *player)
{
    int window_open = 1;
    sfEvent event;

    while (window_open) {
        update_clock(game);
        get_luca_event(game, player, &event, &window_open);
        sfRenderWindow_clear(game->window, sfBlack);
        display_luca_shop(game, player);
        display_all_clothes(game, player);
        display_button_luca(game, player);
        sfRenderWindow_display(game->window);
    }
    return (0);
}
