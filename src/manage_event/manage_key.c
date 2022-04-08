/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_key
*/

#include "structure.h"

static const sfKeyCode keys[4] = {sfKeyQ, sfKeyD, sfKeyZ, sfKeyS};

int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player)
{
    for (int i = 0; i < 4; i++)
        if (key_code == keys[i])
            player->movement[i] = 1;
    if (key_code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    return 0;
}

int manage_key_released(sfKeyCode key_code, player_t *player)
{
    for (int i = 0; i < 4; i++)
        if (key_code == keys[i])
            player->movement[i] = 0;
    return 0;
}
