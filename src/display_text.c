/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_text
*/

#include <stdlib.h>
#include "prototype.h"

int display_guns(game_t *game, player_t *player, int is_destruct)
{
    static char *nbr_bullets = NULL;
    static int old_nbr_bullets = 0;
    sfVector2f nbr_life_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {1700, 900}, game->view);

    if (old_nbr_bullets != player->weapon->ammo) {
        free(nbr_bullets);
        old_nbr_bullets = player->weapon->ammo;
        nbr_bullets = tranform_in_str(player->weapon->ammo);
    }
    if (is_destruct) {
        free(nbr_bullets);
        return 0;
    }
    sfText_setCharacterSize(game->text, 20);
    sfText_setString(game->text, nbr_bullets);
    sfText_setPosition(game->text, nbr_life_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}

int display_money(game_t *game, player_t *player, int is_destruct)
{
    static char *nbr_money = NULL;
    static int old_nbr_money = 0;
    sfVector2f nbr_money_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {1400, 40}, game->view);

    if (old_nbr_money != player->money) {
        free(nbr_money);
        old_nbr_money = player->money;
        nbr_money = tranform_in_str(player->money);
    }
    if (is_destruct) {
        free(nbr_money);
        return 0;
    }
    sfText_setCharacterSize(game->text, 20);
    sfText_setString(game->text, nbr_money);
    sfText_setPosition(game->text, nbr_money_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}
