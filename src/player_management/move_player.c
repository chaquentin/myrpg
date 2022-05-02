/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** rotate_player
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void fill_mouse(game_t *game, player_t *player)
{
    sfVector2i get_mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_pos;
    float rotation = 0.0;
    mouse_pos.x = (float)get_mouse_pos.x - player->pos.x;
    mouse_pos.y = (float)get_mouse_pos.y - player->pos.y;
    if (game->view) {
        mouse_pos.x = (float)get_mouse_pos.x - 960;
        mouse_pos.y = (float)get_mouse_pos.y - 540;
    }
    rotation = atan(mouse_pos.x / mouse_pos.y) * (180.0 / PI) * -1;
    if (mouse_pos.y > 0)
        rotation += 180;
    sfSprite_setOrigin(player->sprite, (sfVector2f) {32, 32});
    sfSprite_setRotation(player->sprite, rotation);
}

int update_movement_sprite(player_t *player, int movement, game_t *game)
{
    static int state = 0;
    static float time = 0.0;

    if (time < 0.3) {
        time += game->delta_time;
        return (0);
    }
    time = 0.0;
    if (movement == 0 || ++state == 4) {
        player->player -= player->player % 4;
        player->clothes->pants -= player->clothes->pants % 4;
        state = 0;
    } else {
        player->player += 1;
        player->clothes->pants += 1;
    }
    player->sprite = game->all_sprite[Player][player->player];
    player->clothes->pants_sprite =
    game->all_sprite[Pants][player->clothes->pants];
    return 0;
}

static int verify_player_collision(player_t *player, sfVector2f pos,
sfVector2f size)
{
    sfIntRect player_hitbox = {(int)player->pos.x - 28,
    (int)player->pos.y - 28, 56, 56};
    sfIntRect wall_hitbox = {(int)pos.x, (int)pos.y, (int)size.x, (int)size.y};

    if (wall_hitbox.width == 0)
        wall_hitbox.width = 1;
    if (wall_hitbox.height == 0)
        wall_hitbox.height = 1;
    if (sfIntRect_intersects(&player_hitbox, &wall_hitbox, NULL))
        return 1;
    return 0;
}

static int manage_player_colision(game_t *game, player_t *player,
sfVector2i movement, int is_x)
{
    sfVector2f wall_start = {0};
    sfVector2f wall_end = {0};
    sfVector2f wall_size = {0};
    sfVector2f player_pos = player->pos;

    for (int i = 0; wall_start.y != -1; i++) {
        wall_start = game->levels[game->current_level]->walls[i].pos1;
        wall_end = game->levels[game->current_level]->walls[i].pos2;
        wall_size.x = wall_end.x - wall_start.x;
        wall_size.y = wall_end.y - wall_start.y;
        if (verify_player_collision(player, wall_start, wall_size) && is_x) {
            player->pos.x -= movement.x * player->speed * game->delta_time;
            break;
        }
        if (verify_player_collision(player, wall_start, wall_size) && !is_x) {
            player->pos.y -= movement.y * player->speed * game->delta_time;
            break;
        }
    }
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
    manage_player_colision(game, player, movement, 1);
    player->pos.y += movement.y * player->speed * game->delta_time;
    manage_player_colision(game, player, movement, 0);
    update_movement_sprite(player, abs(movement.x) + abs(movement.y), game);
}
