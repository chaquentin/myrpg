/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_key
*/

#include "structure.h"

int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player)
{
    switch (key_code) {
        case sfKeyEscape:
        sfRenderWindow_close(game->window);
        break;
        case sfKeyQ:
        player->movement[0] = 1;
        break;
        case sfKeyD:
        player->movement[1] = 1;
        break;
        case sfKeyZ:
        player->movement[2] = 1;
        break;
        case sfKeyS:
        player->movement[3] = 1;
        break;
        default:
        break;
    }
    return 0;
}

int manage_key_released(sfKeyCode key_code, player_t *player)
{
    switch (key_code) {
        case sfKeyQ:
        player->movement[0] = 0;
        break;
        case sfKeyD:
        player->movement[1] = 0;
        break;
        case sfKeyZ:
        player->movement[2] = 0;
        break;
        case sfKeyS:
        player->movement[3] = 0;
        break;
        default:
        break;
    }
    return 0;
}
