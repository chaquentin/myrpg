/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_key
*/

#include "prototype.h"
#include "structure.h"

static const sfKeyCode keys[4] = {sfKeyQ, sfKeyD, sfKeyZ, sfKeyS};

static int reload(game_t *game, player_t *player, int is_input)
{
    static float reload_time = 0.0;
    static int is_reloading = 0;

    if (is_input)
        is_reloading = 1;
    else if (reload_time > player->weapon->reload_time) {
        player->weapon->ammo = player->weapon->ammo_max;
        is_reloading = 0;
        reload_time = 0.0;
    } else
        reload_time += (is_reloading) ? game->delta_time : 0;
    return is_reloading;
}

int shoot(game_t *game, player_t *player, int is_click)
{
    static float last_shoot = 2.0;
    static int is_reloading = 0;

    if (!is_click) {
        is_reloading = reload(game, player, 0);
        last_shoot += game->delta_time;
    }
    if (last_shoot > player->weapon->fire_rate && is_click && !is_reloading) {
        fire_weapon(game, player);
        player->weapon->ammo--;
        last_shoot = 0.0;
    }
}

static int manage_space_pressed(game_t *game, player_t *player)
{
    game->current_level += player->can_change_level;
    player->can_change_level = 0;
    for (int i = 0; i < 4; i++) {
        if (game->all_npc[i]->is_player_seen == sfTrue &&
        game->all_npc[i]->action != NULL) {
            game->all_npc[i]->action(game, player);
        }
    }
}

int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player)
{
    for (int i = 0; i < 4; i++)
        if (key_code == keys[i])
            player->movement[i] = 1;
    if (key_code == sfKeyEscape)
        game->scene = Pause;
    if (key_code == sfKeyR)
        reload(game, player, 1);
    if (key_code == sfKeySpace)
        manage_space_pressed(game, player);
    if (key_code == sfKeyE)
        display_player_stats(game, player);
    return 0;
}

int manage_key_released(sfKeyCode key_code, player_t *player)
{
    for (int i = 0; i < 4; i++)
        if (key_code == keys[i])
            player->movement[i] = 0;
    return 0;
}
