/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** game_display
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

int display_elevator(game_t *game, player_t *player)
{
    const char elvator_txt[] = "Press space to change level";
    sfVector2f txt_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {700, 800}, game->view);

    sfText_setString(game->text, elvator_txt);
    sfText_setPosition(game->text, txt_pos);
    sfText_setCharacterSize(game->text, 10);
    if (player->can_change_level)
        sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}

static int display_health_bar(game_t *game, player_t *player)
{
    sfSprite *health_bar = game->all_sprite[Decor][RedLifeBar];
    sfSprite *health_bar_bg = game->all_sprite[Decor][GreenLifeBar];
    sfSprite *health = game->all_sprite[Decor][Heart];
    sfIntRect health_bar_rect = sfSprite_getTextureRect(health_bar_bg);
    sfVector2f health_bar_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {10, 120}, game->view);

    sfSprite_setPosition(health,
    (sfVector2f) {health_bar_pos.x, health_bar_pos.y - 50});
    sfRenderWindow_drawSprite(game->window, health, NULL);
    health_bar_rect.width = 1 + (player->health);
    sfSprite_setTextureRect(health_bar_bg, health_bar_rect);
    sfSprite_setPosition(health_bar, health_bar_pos);
    sfSprite_setPosition(health_bar_bg, health_bar_pos);
    sfRenderWindow_drawSprite(game->window, health_bar, NULL);
    sfRenderWindow_drawSprite(game->window, health_bar_bg, NULL);
    return 0;
}

int display_health(game_t *game, player_t *player, int is_destruct)
{
    static char *nbr_life = NULL;
    static float old_nbr_life = 0;
    sfVector2f nbr_life_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {100, 40}, game->view);

    if (old_nbr_life != player->health) {
        free(nbr_life);
        old_nbr_life = player->health;
        nbr_life = tranform_in_str((int)player->health);
    }
    if (is_destruct) {
        free(nbr_life);
        return 0;
    }
    display_health_bar(game, player);
    sfText_setCharacterSize(game->text, 20);
    sfText_setString(game->text, nbr_life);
    sfText_setPosition(game->text, nbr_life_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}

int display_game(game_t *game, player_t *player)
{
    display_map_sprite(game);
    if (game->debug)
        enemy_debug(game, player);
    draw_framebuffer(game);
    display_enemies(game);
    display_bullets(game->bullets, game);
    display_player(game, player);
    enemy_actions(game, player);
    display_all_npc(game);
    display_health(game, player, 0);
    display_guns(game, player, 0);
    display_elevator(game, player);
    display_money(game, player, 0);
    sfRenderWindow_display(game->window);
    return 0;
}
