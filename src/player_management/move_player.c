/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** rotate_player
*/

#include <math.h>
#include "structure.h"

void fill_mouse(game_t *game, player_t *player)
{
    sfVector2i get_mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_pos;
    float rotation = 0.0;

    mouse_pos.x = (float)get_mouse_pos.x - player->pos.x;
    mouse_pos.y = (float)get_mouse_pos.y - player->pos.y;
    rotation = atan(mouse_pos.x / mouse_pos.y) * (180.0/PI) * -1;
    sfSprite_setOrigin(player->sprite, (sfVector2f) {32, 32});
    sfSprite_setRotation(player->sprite, rotation);
}

int update_player_sprite(player_t * player, game_t *game, sfVector2f movement)
{
    static float memory_time = 0;

    memory_time += game->delta_time;
    if (memory_time > 0.3) {
        if (movement.x == 0 && movement.y == 0)
            player->actual_sprite = player->default_sprites;
        else if (player->actual_sprite > player->default_sprites + 2)
            player->actual_sprite = player->default_sprites;
        else
            player->actual_sprite += 1;
        player->sprite = game->all_sprite[player->actual_sprite];
        memory_time = 0;
    }
}

void move_player(game_t *game, player_t *player)
{
    sfVector2f movement = {0, 0};

    fill_mouse(game, player);
    movement.x -= player->movement[0];
    movement.x += player->movement[1];
    movement.y -= player->movement[2];
    movement.y += player->movement[3];
    player->pos.x += movement.x * player->speed * game->delta_time;
    player->pos.y += movement.y * player->speed * game->delta_time;
    update_player_sprite(player, game, movement);
}
