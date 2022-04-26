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

enum behaviours get_behaviour(game_t *game, player_t *player, int index)
{
    return Idle;
}

int enemy_actions(game_t *game, player_t *player)
{
    level_t *level = game->levels[game->current_level];
    enemy_t **enemies = level->enemies;

    for (int i = 0; enemies[i]; i++) {
        enemies[i]->behaviour = get_behaviour(game, player, i);
        if (enemies[i]->behaviour == Idle)
            enemy_idle(game, player, i);
    }
}
