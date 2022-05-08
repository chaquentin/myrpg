/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** enemy_init
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "enemies.h"
#include "level.h"
#include "structure.h"
#include "prototype.h"
#include "sprite_sheet.h"

enum enemy_types get_enemy_type(char *str)
{
    if (my_strcmp(str, "Gangster") == 0)
        return Gangster;
    if (my_strcmp(str, "Hoods") == 0)
        return Hoods;
    if (my_strcmp(str, "Durag") == 0)
        return Durag;
    write(1, "Unknown enemy type: ", 21);
    write(1, str, my_strlen(str));
    write(1, "\n", 1);
    return -1;
}

static enemy_t *set_enemy_default_param(enemy_t *enemy)
{
    enemy->current_action = Turn;
    enemy->health = 100;
    enemy->angle = 0.0;
    enemy->last_shot = 0;
    enemy->behaviour = Idle;
    enemy->alive = sfTrue;
    enemy->idled_since = 0;
    return enemy;
}

enemy_t *enemy_create(sfVector2f idle_around, char *name, game_t *game)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy_turn_t *turn = malloc(sizeof(enemy_turn_t));

    if (enemy == NULL || turn == NULL)
        return NULL;
    turn->start_angle = 0.0;
    turn->add_angle = (get_randint(0, 200) - 100) / 500.0;
    enemy->type = get_enemy_type(name);
    if (enemy->type != -1)
        enemy->sprite = game->all_sprite[Enemy][1 + enemy->type * 3];
    enemy->player_pos = (sfVector2f) {-1, -1};
    enemy->pos = idle_around;
    enemy->idle_around = idle_around;
    enemy->next_action = turn;
    enemy = set_enemy_default_param(enemy);
    return enemy;
}

enemy_t **enemies_create(char *enemies_data, game_t *game)
{
    char **enemies = my_str_to_word_array(enemies_data, "\n");
    int nbr_enemies = my_atoi(enemies[0]);
    enemy_t **enemy_array = malloc(sizeof(enemy_t *) * (nbr_enemies + 1));
    char **enemy = NULL;

    if (enemy_array == NULL || enemies == NULL)
        return NULL;
    for (int i = 0; i < NBR_ENEMIES; i++)
        sfSprite_setOrigin(game->all_sprite[Enemy][i], (sfVector2f) {32, 32});
    enemy_array[nbr_enemies] = NULL;
    for (int i = 0; i < nbr_enemies; i++) {
        enemy = my_str_to_word_array(enemies[i + 1], " ");
        enemy_array[i] = enemy_create((sfVector2f) {my_atoi(enemy[1]) + 0.5,
        my_atoi(enemy[2]) + 0.5}, enemy[0], game);
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
        free(enemies[i]->next_action);
        free(enemies[i]);
    }
    free(enemies);
}
