/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** quentin_action
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static int display_shop(game_t *game, sfSprite **sprite, button_t **buy_button)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {700, 30}, game->view);

    sfSprite_setPosition(sprite[0], pos);
    sfRenderWindow_drawSprite(game->window, sprite[0], NULL);
    for (int i = 1; i < 4; i++) {
        pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {800, 100 + (i - 1) * 150}, game->view);
        sfSprite_setPosition(sprite[i], pos);
        sfRenderWindow_drawSprite(game->window, sprite[i], NULL);
    }
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(buy_button[i]->sprite, buy_button[i]->pos);
        sfRenderWindow_drawSprite(game->window, buy_button[i]->sprite, NULL);
    }
    return 0;
}

int manage_view_mouse(game_t *game, sfEvent *event, button_t **all_button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f fmouse = sfRenderWindow_mapPixelToCoords(game->window, mouse,
    game->view);

    for (int i = 0; all_button[i]; i++) {
        manage_click(all_button[i], fmouse, game);
    }
}

static int get_quentin_event(game_t *game, player_t *player, sfEvent *event,
button_t **buy_buttons)
{
    int ret_value = 1;

    manage_view_mouse(game, event, buy_buttons);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        event->key.code == sfKeyEscape)
            ret_value = 0;
    }
    return (ret_value);
}

sfSprite **create_shop_sprites(game_t *game)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 5);

    sprites[0] = game->all_sprite[Decor][ClothesShop];
    sprites[1] = game->all_sprite[Decor][Coke];
    sprites[2] = game->all_sprite[Decor][Canabis];
    sprites[3] = game->all_sprite[Decor][Crake];
    sprites[4] = NULL;
    return sprites;
}

button_t **create_buy_buttons(game_t *game)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);

    for (int i = 0; i < 3; i++) {
        buttons[i] = create_button(Buy1, game, Game);
        buttons[i]->pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {800, 200 + i * 250}, game->view);
    }
    buttons[3] = NULL;
    return buttons;
}

int quentin_action(game_t *game, player_t *player)
{
    int window_open = 1;
    sfEvent event;
    sfSprite **sprite = create_shop_sprites(game);
    button_t **buy_buttons = create_buy_buttons(game);

    while (window_open) {
        update_clock(game);
        window_open = get_quentin_event(game, player, &event, buy_buttons);
        sfRenderWindow_clear(game->window, sfBlack);
        display_shop(game, sprite, buy_buttons);
        sfRenderWindow_display(game->window);
    }
    for (int i = 0; i < 4; i++)
        player->movement[i] = 0;
    free(sprite);
    return 0;
}
