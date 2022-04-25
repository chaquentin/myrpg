/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** draw_rays
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "prototype.h"
#include "structure.h"

sfVector2f to_int(sfVector2f pos)
{
    sfVector2f new_pos = {(int)pos.x, (int)pos.y};
    return (new_pos);
}

void draw_rays(player_t *player, game_t *game, line_t *walls)
{
    sfVector2f inter = {-1, -1};

    for (int i = 0; walls[i].pos1.x != -1; i++) {
        for (int j = 0; walls[j].pos1.x != -1; j++) {
            inter = is_intersection(to_int(player->pos), to_int(walls[j].pos1), to_int(walls[i].pos1), to_int(walls[i].pos2));
            draw_point(game->window, inter, sfRed, 2);
            inter = is_intersection(to_int(player->pos), to_int(walls[j].pos2), to_int(walls[i].pos1), to_int(walls[i].pos2));
            draw_point(game->window, inter, sfRed, 2);
            printf("%f;%f %f;%f : %f;%f %f;%f -> %f;%f\n",
                player->pos.x, player->pos.y,
                walls[j].pos1.x, walls[j].pos1.y,
                walls[i].pos1.x, walls[i].pos1.y,
                walls[j].pos2.x, walls[j].pos2.y,
                inter.x, inter.y);
        }
    }
}
