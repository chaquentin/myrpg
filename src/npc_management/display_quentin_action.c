/*
** EPITECH PROJECT, 2022
** rpg_test
** File description:
** display_quentin_action
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

int dispay_price_and_description(game_t *game)
{
    sfVector2f pos = {0};
    char drug[3][100] = {"Coke 50 dollars\nIncrease your speed",
    "Weed 10 dollars\nIncrease your damage reduction",
    "Crake 20 dollars\nRestore your life"};

    sfText_setCharacterSize(game->text, 30);
    for (int i = 0; i < 3; i++) {
        pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {1000, 120 + i * 250}, game->view);
        sfText_setString(game->text, drug[i]);
        sfText_setPosition(game->text, pos);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    return 0;
}

int display_shop(game_t *game, sfSprite **sprite, button_t **buy_button,
player_t *player)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {700, 30}, game->view);

    for (int i = 0; i < 4; i++) {
        sfSprite_setPosition(sprite[i], pos);
        sfRenderWindow_drawSprite(game->window, sprite[i], NULL);
        pos = sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i) {800, 100 + i * 250}, game->view);
    }
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(buy_button[i]->sprite, buy_button[i]->pos);
        sfRenderWindow_drawSprite(game->window, buy_button[i]->sprite, NULL);
    }
    display_money(game, player, 0);
    return dispay_price_and_description(game);
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

int get_quentin_event(game_t *game, player_t *player, sfEvent *event,
button_t **buy_buttons)
{
    int ret_value = 1;

    manage_view_mouse(game, event, buy_buttons);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        event->key.code == sfKeyEscape)
            ret_value = 0;
        if (event->type == sfEvtMouseButtonReleased)
            buy_drug(game, player, buy_buttons);
    }
    return (ret_value);
}
