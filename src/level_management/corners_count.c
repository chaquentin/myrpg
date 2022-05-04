/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** corners_count
*/

#include <SFML/Graphics.h>
#include "structure.h"

int count_adjacent_walls(level_t *level, sfVector2i pos)
{
    int count = 4;
    char n = (pos.y > 0) ? level->map[pos.y - 1][pos.x] : '0';
    char s = (pos.y < level->size.y - 1) ? level->map[pos.y + 1][pos.x] : '0';
    char e = (pos.x < level->size.x - 1) ? level->map[pos.y][pos.x + 1] : '0';
    char w = (pos.x > 0) ? level->map[pos.y][pos.x - 1] : '0';

    if (level->map[pos.y][pos.x] == 'W' || level->map[pos.y][pos.x] == 'w') {
        count -= (n == 'W' || n == 'w');
        count -= (s == 'W' || s == 'w');
        count -= (e == 'W' || e == 'w');
        count -= (w == 'W' || w == 'w');
        return (count);
    }
    return 0;
}

int count_real_walls(level_t *level)
{
    int nbr = 0;

    for (int i = 0; i < 32 * 18; i++)
        nbr += (level->map[i / 32][i % 32] == 'W'
        || level->map[i / 32][i % 32] == 'w');
    return (nbr);
}

int count_walls(level_t *level)
{
    int count = 0;

    for (int y = 0; y < level->size.y; y++)
        for (int x = 0; x < level->size.x; x++)
            count += count_adjacent_walls(level, (sfVector2i) {x, y});
    return count + (count_real_walls(level) * 2);
}
