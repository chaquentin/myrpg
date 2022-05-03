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

int fire_weapon(game_t *game, player_t *player)
{
    bullet_t *bullet = create_bullet(game, player->pos, player->weapon->damage,
    sfSprite_getRotation(player->sprite));

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
        tmp->pos.y -= 5 * cos(tmp->angle * M_PI / 180);
        tmp->pos.x += 5 * sin(tmp->angle * M_PI / 180);
        tmp = tmp->next;
    }
    
}
