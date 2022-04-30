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
        sfSound_play(player->weapon->sound);
        player->weapon->ammo--;
        last_shoot = 0.0;
    }
}

int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player)
{
    for (int i = 0; i < 4; i++)
        if (key_code == keys[i])
            player->movement[i] = 1;
    if (key_code == sfKeyEscape)
        game->scene = Quit;
    if (key_code == sfKeyR)
        reload(game, player, 1);
    if (key_code == sfKeySpace)
        player->is_clicked = sfTrue;
    if (key_code == sfKeyE)
        if (player->weapon->weapon < 10)
            change_weapon(player, game, player->weapon->weapon + 1);
        else
            change_weapon(player, game, 0);
    return 0;
}

int manage_key_released(sfKeyCode key_code, player_t *player)
{
    for (int i = 0; i < 4; i++)
        if (key_code == keys[i])
            player->movement[i] = 0;
    if (key_code == sfKeySpace)
        player->is_clicked = sfFalse;
    return 0;
}
