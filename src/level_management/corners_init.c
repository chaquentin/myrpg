/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** corners_init
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"

int is_collide(sfVector2f player, sfVector2f pos, line_t *walls)
{
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;

    for (int i = 0; walls[i].pos1.x != -1; i++) {
        pos1 = walls[i].pos1;
        pos2 = walls[i].pos2;
        pos3 = is_intersection(player, pos, pos1, pos2);
        if (get_distance(pos3, pos) < 100)
            return 0;
    }
    return 1;
}

line_t get_coos(sfVector2i pos, level_t *level, char c)
{
    line_t line = (line_t) {(sfVector2f) {-1, -1}, (sfVector2f) {-1, -1}};

    if (c == 'N' || c == 'W')
        line.pos1 = (sfVector2f) {pos.x, pos.y};
    if (c == 'S')
        line.pos1 = (sfVector2f) {pos.x, pos.y + 1};
    if (c == 'E')
        line.pos1 = (sfVector2f) {pos.x + 1, pos.y};
    if (c == 'N')
        line.pos2 = (sfVector2f) {pos.x + 1, pos.y};
    if (c == 'S' || c == 'E')
        line.pos2 = (sfVector2f) {pos.x + 1, pos.y + 1};
    if (c == 'W')
        line.pos2 = (sfVector2f) {pos.x, pos.y + 1};
    line.pos1.x *= (64 * 0.9375);
    line.pos1.y *= (64 * 0.9375);
    line.pos2.x *= (64 * 0.9375);
    line.pos2.y *= (64 * 0.9375);
    return line;
}

int add_wall(sfVector2i pos, level_t *level, line_t *walls, int index)
{
    char n = (pos.y > 0) ? level->map[pos.y - 1][pos.x] : '0';
    char s = (pos.y < level->size.y - 1) ? level->map[pos.y + 1][pos.x] : '0';
    char e = (pos.x < level->size.x - 1) ? level->map[pos.y][pos.x + 1] : '0';
    char w = (pos.x > 0) ? level->map[pos.y][pos.x - 1] : '0';
    int count = 0;
    char direction[4] = {n, s, e, w};
    char write_direction[4] = {'N', 'S', 'E', 'W'};

    if (is_in("WwEe", level->map[pos.y][pos.x]) != 1)
        return 0;
    for (int i = 0; i < 4; i++) {
        if (is_in("WwEe", direction[i]) != 1) {
            walls[index + count] = get_coos(pos, level, write_direction[i]);
            count++;
        }
    }
    return count;
}

line_t *create_map_walls(level_t *level, game_t *game)
{
    int nbr_walls = count_walls(level);
    line_t *walls = malloc(sizeof(line_t) * (nbr_walls + 1));
    sfVector2i p = {0, 0};
    int index = 0;
    float size = (64 * 0.9375);

    walls[nbr_walls] = (line_t) {(sfVector2f) {-1, -1}, (sfVector2f) {-1, -1}};
    for (int i = 0; i < level->size.y * level->size.x; i++) {
        p.y = i / level->size.x;
        p.x = i % level->size.x;
        if (is_in("WwEe", level->map[p.y][p.x]) == 1) {
            walls[index] = (line_t) {(sfVector2f) {p.x * size, p.y * size},
            (sfVector2f) {(p.x + 1) * size, (p.y + 1) * size}};
            walls[index + 1] = (line_t) {(sfVector2f) {p.x * size, (p.y + 1) *
            size}, (sfVector2f) {(p.x + 1) * size, p.y * size}};
            index += 2;
        }
        index += (add_wall((sfVector2i) {p.x, p.y}, level, walls, index));
    }
    return walls;
}

void destroy_map_walls(line_t *walls)
{
    if (!walls)
        return;
    free(walls);
}
