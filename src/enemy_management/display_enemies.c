/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_enemies
*/

#include <SFML/Graphics.h>
#include "enemies.h"
#include "level.h"
#include "structure.h"

void display_enemy(sfRenderWindow *window, enemy_t *enemy)
{
    if (enemy->alive == sfTrue && enemy->type != -1 && enemy->sprite != NULL) {
        sfSprite_setPosition(enemy->sprite, enemy->pos);
        sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
    }
}

void display_enemies(game_t *game)
{
    enemy_t **enemy = game->levels[game->current_level]->enemies;
    sfRenderWindow *window = game->window;

    for (int i = 0; enemy[i]; i++)
        display_enemy(window, enemy[i]);
}
