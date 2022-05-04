/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** enemy_move
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

sfVector2f get_multiple_pos(sfVector2f pos, int i)
{
    int size = 10;

    switch (i) {
    case 0:
        return (sfVector2f) {pos.x, pos.y};
    case 1:
        return (sfVector2f) {pos.x + size, pos.y};
    case 2:
        return (sfVector2f) {pos.x - size, pos.y};
    case 3:
        return (sfVector2f) {pos.x, pos.y + size};
    case 4:
        return (sfVector2f) {pos.x, pos.y - size};
    default:
        return (sfVector2f) {pos.x, pos.y};
    }
}

sfVector2f spots_player(game_t *game, player_t *player, int index)
{
    enemy_t *enemy = game->levels[game->current_level]->enemies[index];
    line_t *walls = game->levels[game->current_level]->walls;
    sfVector2f inter = {-1, -1};
    float distance = 0;
    int is_inter = 0;

    for (int i = 0; walls[i].pos1.x != -1; i++) {
        for (int j = 0; j < 5; j++) {
            inter = is_intersection(get_multiple_pos(enemy->pos, j),
            get_multiple_pos(player->pos, j), walls[i].pos1, walls[i].pos2);
            is_inter += (inter.x != -1);
        }
    }
    distance = get_distance(enemy->pos, player->pos);
    if (is_inter == 0 && distance < VIEW_DISTANCE) {
        enemy->player_pos = player->pos;
        return player->pos;
    }
    return (sfVector2f) {-1, -1};
}

enum behaviours get_behaviour(game_t *game, player_t *player, int index)
{
    enemy_t *enemy = game->levels[game->current_level]->enemies[index];
    enum behaviours behaviour = enemy->behaviour;
    sfVector2f pos = spots_player(game, player, index);

    if (enemy->player_pos.x != -1) {
        behaviour = Searching;
        if (get_distance(enemy->pos, player->pos) < shooting_dist[enemy->type]
        && pos.x != -1)
            behaviour = Attacking;
    }
    if (get_distance(enemy->pos, enemy->player_pos) < 10) {
        behaviour = Idle;
        enemy->player_pos = (sfVector2f) {-1, -1};
    }
    return behaviour;
}

int enemy_actions(game_t *game, player_t *player)
{
    level_t *level = game->levels[game->current_level];
    enemy_t **enemies = level->enemies;

    for (int i = 0; enemies[i]; i++) {
        if (enemies[i]->type == -1 || enemies[i]->alive == sfFalse)
            continue;
        enemies[i]->behaviour = get_behaviour(game, player, i);
        if (enemies[i]->behaviour == Idle)
            enemy_idle(game, player, i);
        if (enemies[i]->behaviour == Searching)
            enemy_search(game, player, i);
        if (enemies[i]->behaviour == Attacking)
            enemy_attack(game, player, i);
    }
}
