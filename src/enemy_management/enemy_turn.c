/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** enemy_turn
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "structure.h"
#include "prototype.h"

int enemy_turn(game_t *game, enemy_t *enemy)
{
    enemy_turn_t *turn = NULL;

    turn = enemy->next_action;
    if (enemy->idled_since == 0) {
        free(enemy->next_action);
        turn = malloc(sizeof(enemy_turn_t));
        turn->start_angle = sfSprite_getRotation(enemy->sprite);
        turn->add_angle = (get_randint(0, 200) - 100) / 500.0;
    }
    enemy->next_action = turn;
    sfSprite_setRotation(enemy->sprite, turn->start_angle + (turn->add_angle
    * enemy->idled_since));
    return 0;
}
