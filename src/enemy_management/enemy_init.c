/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** enemy_init
*/

#include <stdio.h>
#include <stdlib.h>
#include "enemies.h"
#include "level.h"
#include "structure.h"
#include "prototype.h"
#include "sprite_sheet.h"

enum enemies get_enemy_type(char *str)
{
    if (my_strcmp(str, "EnemyGun1") == 0)
        return EnemyGun1;
    if (my_strcmp(str, "EnemyGun2") == 0)
        return EnemyGun2;
    return -1;
}

enemy_t *enemy_create(sfVector2f idle_around, char *name, game_t *game)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy_jump_t *jump = malloc(sizeof(enemy_jump_t));

    if (!enemy || !jump)
        return NULL;
    enemy->type = get_enemy_type(name);
    enemy->sprite = NULL;
    if (enemy->type != -1)
        enemy->sprite = sfSprite_copy(game->all_sprite[Enemy][enemy->type]);
    jump->is_jumping = sfFalse;
    enemy->player_pos = (sfVector2f) {-1, -1};
    enemy->pos = idle_around;
    enemy->idle_around = idle_around;
    enemy->jump_rate = 1000;
    enemy->alive = sfTrue;
    enemy->idled_since = 0;
    enemy->jump = jump;
    enemy->behaviour = Idle;
    return enemy;
}

enemy_t **enemies_create(char *enemies_data, game_t *game)
{
    char **enemies = my_str_to_word_array(enemies_data, "\n");
    int nbr_enemies = my_atoi(enemies[0]);
    enemy_t **enemy_array = malloc(sizeof(enemy_t *) * (nbr_enemies + 1));
    char **enemy = NULL;

    enemy_array[nbr_enemies] = NULL;
    for (int i = 0; i < nbr_enemies; i++) {
        enemy = my_str_to_word_array(enemies[i + 1], " ");
        enemy_array[i] = enemy_create((sfVector2f) {my_atoi(enemy[1]),
        my_atoi(enemy[2])}, enemy[0], game);
        my_free_word_array(enemy);
    }
    my_free_word_array(enemies);
    return enemy_array;
}

void destroy_enemies(enemy_t **enemies)
{
    if (!enemies)
        return;
    for (int i = 0; enemies[i]; i++) {
        if (enemies[i]->type != -1 && enemies[i]->sprite)
            sfSprite_destroy(enemies[i]->sprite);
        free(enemies[i]->jump);
        free(enemies[i]);
    }
    free(enemies);
    return;
}
