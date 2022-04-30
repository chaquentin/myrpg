/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** start_game
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static void get_game_event(game_t *game, sfEvent *event, player_t *player)
{
    shoot(game, player, 0);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed)
            manage_key_pressed(game, event->key.code, player);
        if (event->type == sfEvtKeyReleased)
            manage_key_released(event->key.code, player);
    }
    if (player->is_clicked && player->weapon->ammo > 0)
        shoot(game, player, 1);
}

int update_clock(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;
    static float old_seconds = 0.0;

    game->delta_time = seconds - old_seconds;
    old_seconds = seconds;
    if (seconds > 10) {
        sfClock_restart(game->clock);
        old_seconds = 0.0;
    }
    return (0);
}

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

int display_health(game_t *game, player_t *player, int is_destruct)
{
    static char *nbr_life = NULL;
    static int old_nbr_life = 0;
    sfVector2f nbr_life_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {10, 10}, game->view);

    if (old_nbr_life != player->health) {
        free(nbr_life);
        old_nbr_life = player->health;
        nbr_life = tranform_in_str(player->health);
    }
    if (is_destruct) {
        free(nbr_life);
        return 0;
    }
    sfText_setCharacterSize(game->text, 20);
    sfText_setString(game->text, nbr_life);
    sfText_setPosition(game->text, nbr_life_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}

int display(game_t *game, player_t *player)
{
    display_map_sprite(game);
    display_enemies(game);
    display_player(game, player);
    display_health(game, player, 0);
    display_guns(game, player, 0);
    sfRenderWindow_display(game->window);
    return 0;
}

int game(game_t *game, player_t *player, sfEvent event)
{
    update_clock(game);
    view_update(game, player);
    sfRenderWindow_clear(game->window, sfBlack);
    get_game_event(game, &event, player);
    move_player(game, player);
    fill_mouse(game, player);
    display(game, player);
    return 0;
}
