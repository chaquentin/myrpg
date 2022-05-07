/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_collision_enemy
*/

#include <stdio.h>
#include "structure.h"
#include "prototype.h"

int display_hitbox(game_t *game, sfIntRect hitbox, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, (sfVector2f) {hitbox.left, hitbox.top});
    sfRectangleShape_setSize(rectangle, (sfVector2f) {hitbox.width, hitbox.height});
    sfRectangleShape_setFillColor(rectangle, color);
    sfRenderWindow_drawRectangleShape(game->window, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
    return 0;
}

static int collision_enemy(game_t *game, enemy_t *enemy, sfIntRect hitbox,
sfVector2f movement)
{
    if (hitbox.width == 3 && hitbox.height == 3)
        return 0;
    if (hitbox.width == 3)
        enemy->pos.x = movement.x;
    if (hitbox.height == 3)
        enemy->pos.y = movement.y;
    return 0;
}

int manage_enemy_colision(game_t *game, enemy_t *enemy,
sfVector2f movement)
{
    sfIntRect enemy_hitbox = {(int) enemy->pos.x - 28, (int) enemy->pos.y - 28, 56, 56};
    sfIntRect wall_hitbox = {0, 0, 0, 0};
    line_t *walls = game->levels[game->current_level]->walls;
    int height = 0;
    int width = 0;

    for (int i = 0; walls[i].pos1.x != -1; i++) {
        height = 3;
        width = 3;
        if (walls[i].pos1.x != walls[i].pos2.x && walls[i].pos1.y != walls[i].pos2.y)
            continue;
        if (walls[i].pos1.x == walls[i].pos2.x)
            height = walls[i].pos2.y - walls[i].pos1.y;
        if (walls[i].pos1.y == walls[i].pos2.y)
            width = walls[i].pos2.x - walls[i].pos1.x;
        wall_hitbox = (sfIntRect) {walls[i].pos1.x, walls[i].pos1.y, width, height};
        if (sfIntRect_intersects(&enemy_hitbox, &wall_hitbox, NULL))
            collision_enemy(game, enemy, wall_hitbox, movement);
        else
            enemy->pos = movement;
    }
    return 0;
}

