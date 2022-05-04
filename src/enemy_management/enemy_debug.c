/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** enemy_debug
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

int enemy_debug(game_t *game, player_t *player)
{
    level_t *level = game->levels[game->current_level];
    enemy_t **enemies = level->enemies;
    sfColor color = sfWhite;
    line_t *walls = level->walls;

    for (int i = 0; walls[i].pos1.x != -1; i++) {
        if (walls[i].pos1.x != walls[i].pos2.x && walls[i].pos1.y != walls[i].pos2.y)
            color = sfRed;
        else
            color = sfGreen;
        draw_line(game, walls[i].pos1, walls[i].pos2, color, 2);
    }

    for (int i = 0; enemies[i]; i++) {
        if (enemies[i]->type == -1)
            continue;
        if (enemies[i]->behaviour == Idle)
            color = sfWhite;
        if (enemies[i]->behaviour == Searching)
            color = sfYellow;
        if (enemies[i]->behaviour == Attacking)
            color = sfRed;

        draw_circle(game->window, enemies[i]->pos, shooting_dist[enemies[i]->type], color);
        draw_circle(game->window, enemies[i]->pos, VIEW_DISTANCE, color);
    }
}
