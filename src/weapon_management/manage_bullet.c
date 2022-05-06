/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_bullet
*/

#include "structure.h"
#include "prototype.h"

static int manage_bullet_player_collision(game_t *game, player_t *player,
bullet_t *bullet)
{
    sfIntRect bullet_hitbox = {bullet->pos.x, bullet->pos.y, 20, 20};
    sfIntRect player_hitbox = {player->pos.x - 32, player->pos.y - 32, 64, 64};

    if (bullet->fired_from == PlayerType)
        return 0;
    if (sfIntRect_intersects(&bullet_hitbox, &player_hitbox, NULL)) {
        player->health -= (bullet->damage) *
        ((100 - player->damage_reduction) / 100.0);
        remove_id(game->bullets, bullet->id);
        return (1);
    }
    return (0);
}

static int verify_enemy_dead(enemy_t **enemy, player_t *player, int i)
{
    if (enemy[i]->alive == sfTrue && enemy[i]->health <= 0) {
        enemy[i]->alive = sfFalse;
        player->swag += player->weapon->swag;
        player->xp += 2 * ((1 + enemy[i]->type) * (1 + enemy[i]->type));
    }
}

static int manage_bullet_enemy_colision(game_t *game, bullet_t *bullet,
player_t *player)
{
    enemy_t **enemy = game->levels[game->current_level]->enemies;
    sfIntRect bullet_hitbox = {bullet->pos.x, bullet->pos.y, 20, 20};
    sfIntRect enemy_hitbox = {0};

    for (int i = 0; enemy[i]; i++) {
        enemy_hitbox = (sfIntRect) {enemy[i]->pos.x - 30, enemy[i]->pos.y - 30,
        54, 54};
        if (enemy[i]->type == -1 || enemy[i]->alive == sfFalse
        || bullet->fired_from == EnemyType)
            continue;
        if (sfIntRect_intersects(&bullet_hitbox, &enemy_hitbox, NULL)) {
            game->levels[game->current_level]->enemies[i]->health -=
            bullet->damage;
            verify_enemy_dead(enemy, player, i);
            remove_id(game->bullets, bullet->id);
            return (1);
        }
    }
    return (0);
}

static int manage_bullet_wall_colision(game_t *game, bullet_t *bullet)
{
    line_t *all_wall = game->levels[game->current_level]->walls;
    sfIntRect wall_hitbox = {0};
    sfIntRect bullet_hitbox = {bullet->pos.x, bullet->pos.y, 20, 20};

    for (int i = 0; all_wall[i].pos1.x >= 0; i++) {
        wall_hitbox.left = all_wall[i].pos1.x;
        wall_hitbox.top = all_wall[i].pos1.y;
        wall_hitbox.width = all_wall[i].pos2.x - all_wall[i].pos1.x;
        wall_hitbox.height = all_wall[i].pos2.y - all_wall[i].pos1.y;
        wall_hitbox.width = (wall_hitbox.width) ? wall_hitbox.width : 1;
        wall_hitbox.height = (wall_hitbox.height) ? wall_hitbox.height : 1;
        if (sfIntRect_intersects(&bullet_hitbox, &wall_hitbox, NULL)) {
            remove_id(game->bullets, bullet->id);
            return (1);
        }
    }
    return (0);
}

int manage_bullet(game_t *game, player_t *player)
{
    bullet_t *bullet = game->bullets->first;
    bullet_t *next = NULL;

    while (bullet != NULL) {
        next = bullet->next;
        if (!manage_bullet_enemy_colision(game, bullet, player) &&
        !manage_bullet_player_collision(game, player, bullet))
            manage_bullet_wall_colision(game, bullet);
        bullet = next;
    }
    return (0);
}
