/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** fire_weapon
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"
#include "prototype.h"

int fire_weapon_enemy(game_t *game, enemy_t *enemy)
{
    bullet_t *bullet = create_bullet(game, enemy->pos,
    shooting_damage[enemy->type], enemy->angle);

    bullet->fired_from = EnemyType;
    if (bullet == NULL)
        return 84;
    append(game->bullets, bullet);
    return 0;
}

int fire_weapon(game_t *game, player_t *player)
{
    bullet_t *bullet = NULL;
    int damage = player->weapon->damage;

    if (rand() % 100 < player->crit_rate)
        damage *= 2;
    bullet = create_bullet(game, player->pos, damage,
    sfSprite_getRotation(player->sprite));
    bullet->fired_from = PlayerType;
    if (bullet == NULL)
        return 84;
    append(game->bullets, bullet);
    return 0;
}

int update_bullets(game_t *game)
{
    all_bullet_t *bullets = game->bullets;
    bullet_t *tmp = bullets->first;

    while (tmp != NULL) {
        tmp->pos.y -= 1000 * cos(tmp->angle * M_PI / 180) * game->delta_time;
        tmp->pos.x += 1000 * sin(tmp->angle * M_PI / 180) * game->delta_time;
        tmp = tmp->next;
    }
}
