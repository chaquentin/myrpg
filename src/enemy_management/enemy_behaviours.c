/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** enemy_behaviours
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "structure.h"
#include "prototype.h"
#include "enemies.h"

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
    switch (enemy->current_action) {
    case Sound:
        break;
    case Jump:
        break;
    case Turn:
        enemy_turn(game, enemy);
        break;
    }
}

int enemy_search(game_t *game, player_t *player, int index)
{
    enemy_t *enemy = game->levels[game->current_level]->enemies[index];
    sfVector2f pos = {0, 0};

    enemy->angle = get_angle(enemy->pos, enemy->player_pos);
    pos.x = enemy->pos.x + (cos(enemy->angle) * ENEMY_SPEED
    * game->delta_time);
    pos.y = enemy->pos.y + (sin(enemy->angle) * ENEMY_SPEED
    * game->delta_time);
    manage_enemy_colision(game, enemy, pos);
    return 0;
}

int enemy_attack(game_t *game, player_t *player, int index)
{
    enemy_t *enemy = game->levels[game->current_level]->enemies[index];

    enemy->angle = get_angle(enemy->pos, enemy->player_pos);

    if (enemy->last_shot >= shooting_speed[enemy->type] * (0.1 / game->delta_time)) {
        enemy->last_shot = 0;
        fire_weapon_enemy(game, enemy);
    } else
        enemy->last_shot++;
    return 0;
}
