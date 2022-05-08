/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_collision
*/

#include "structure.h"

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

static int verify_wall_collision(player_t *player, game_t *game,
sfVector2i movement, int is_x)
{
    sfVector2f wall_start = {0};
    sfVector2f wall_end = {0};
    sfVector2f wall_size = {0};

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

int manage_player_colision(game_t *game, player_t *player,
sfVector2i movement)
{
    sfVector2f player_pos = player->pos;
    sfIntRect npc_size = {0};
    static int is_x = 0;

    is_x = (is_x == 0) ? 1 : 0;
    for (int i = 0; i < 4; i++) {
        if (verify_player_collision(player, game->all_npc[i]->pos,
        (sfVector2f) {64, 54}) && is_x && game->current_level == 0) {
            player->pos.x -= movement.x * player->speed * game->delta_time;
            return 0;
        } else if (verify_player_collision(player, game->all_npc[i]->pos,
        (sfVector2f) {64, 54}) && !is_x && game->current_level == 0) {
            player->pos.y -= movement.y * player->speed * game->delta_time;
            return 0;
        }
    }
    verify_wall_collision(player, game, movement, is_x);
    return 0;
}
