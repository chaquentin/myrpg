/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** rotate_player
*/

#include <math.h>
#include <stdlib.h>
#include "structure.h"

void fill_mouse(game_t *game, player_t *player)
{
    sfVector2i get_mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_pos;
    float rotation = 0.0;

    mouse_pos.x = (float)get_mouse_pos.x - player->pos.x;
    mouse_pos.y = (float)get_mouse_pos.y - player->pos.y;
    rotation = atan(mouse_pos.x / mouse_pos.y) * (180.0/PI) * -1;
    if (mouse_pos.y > 0)
        rotation += 180;
    sfSprite_setOrigin(player->sprite, (sfVector2f) {32, 32});
    sfSprite_setRotation(player->sprite, rotation);
}

int update_movement_sprite(player_t *player, int movement, game_t *game)
{
    clothes_t *clothes = player->clothes;
    static int state = 0;
    static float time = 0.0;

    if (time < 0.3) {
        time += game->delta_time;
        return (0);
    }
    time = 0.0;
    state += 1;
    if (movement == 0 || state == 4) {
        player->player -= player->player % 4;
        player->clothes->pants -= player->clothes->pants % 4;
        state = 0;
    } else {
        player->player += 1;
        player->clothes->pants += 1;
    }
    player->sprite = game->all_sprite[Nigger][player->player];
    player->clothes->pants_sprite = game->all_sprite[Pants][clothes->pants];
    return 0;
}

void move_player(game_t *game, player_t *player)
{
    sfVector2i movement = {0, 0};

    fill_mouse(game, player);
    movement.x -= player->movement[0];
    movement.x += player->movement[1];
    movement.y -= player->movement[2];
    movement.y += player->movement[3];
    player->pos.x += movement.x * player->speed * game->delta_time;
    player->pos.y += movement.y * player->speed * game->delta_time;
    update_movement_sprite(player, abs(movement.x) + abs(movement.y), game);
}
