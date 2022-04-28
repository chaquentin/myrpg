/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** enemy_move
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "structure.h"
#include "prototype.h"

int enemy_idle(game_t *game, player_t *player, int index)
{
    enemy_t *enemy = game->levels[game->current_level]->enemies[index];
    
    if (enemy->type == -1)
        return 84;
    if (get_randint(MIN_TIME_IDLE, MAX_TIME_IDLE) < enemy->idled_since) {
        enemy->idled_since = -1;
        enemy->current_action = get_randint(0, NBR_ACTIONS);
        return 0;
    }
    enemy->idled_since++;
    switch (enemy->current_action)
    {
    case Sound:
        break;
    case Jump:
        break;
    case Turn:
        enemy_turn(game, enemy);
        break;
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
        inter = is_intersection(enemy->pos, player->pos, walls[i].pos1, walls[i].pos2);
        if (inter.x != -1) {
            is_inter++;
            //draw_line(game, walls[i].pos1, walls[i].pos2, sfGreen, 2);
            //draw_point(game->window, inter, sfRed, 5);
        }
    }
    distance = get_distance(enemy->pos, player->pos);
    if (is_inter == 0 && distance < VIEW_DISTANCE) {
        enemy->player_pos = player->pos;
        return player->pos;
    }
    enemy->player_pos = (sfVector2f){-1, -1};
    return (sfVector2f){-1, -1};
}

enum behaviours get_behaviour(game_t *game, player_t *player, int index)
{
    enemy_t *enemy = game->levels[game->current_level]->enemies[index];
    enum behaviours behaviour = enemy->behaviour;
    sfVector2f pos = spots_player(game, player, index);

    /*
    if (enemy->player_pos.x == -1)
        printf("invisible\n");
    else {
        printf("visible\n");
        behaviour = Searching;
    }
    */

    return behaviour;
}

int enemy_actions(game_t *game, player_t *player)
{
    level_t *level = game->levels[game->current_level];
    enemy_t **enemies = level->enemies;

    for (int i = 0; enemies[i]; i++) {
        if (enemies[i]->type == -1)
            continue;
        enemies[i]->behaviour = get_behaviour(game, player, i);
        if (enemies[i]->behaviour == Idle)
            enemy_idle(game, player, i);
    }
}
