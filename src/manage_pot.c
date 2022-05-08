/*
** EPITECH PROJECT, 2022
** rpg_test
** File description:
** manage_drug
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static int take_drug(enum decor witch_drug, player_t *player)
{
    player->inventory->drug_object = witch_drug;
    player->inventory->drug_time = 0.0;
    player->inventory->nbr_object--;
    return 0;
}

int use_drug(game_t *game, player_t *player, button_t **button)
{
    if (button[0]->is_click == sfTrue && player->inventory->fst_object != -1 &&
    player->inventory->drug_object == -1) {
        take_drug(player->inventory->fst_object, player);
        player->inventory->fst_object = -1;
    }
    if (button[1]->is_click == sfTrue && player->inventory->snd_object != -1 &&
    player->inventory->drug_object == -1) {
        take_drug(player->inventory->snd_object, player);
        player->inventory->snd_object = -1;
    }
    if (button[2]->is_click == sfTrue && player->inventory->trd_object != -1 &&
    player->inventory->drug_object == -1) {
        take_drug(player->inventory->trd_object, player);
        player->inventory->trd_object = -1;
    }
}

static int manage_drug_malus(game_t *game, inventory_t *inventory,
player_t *player)
{
    if (inventory->drug_object >= 0 && inventory->drug_object <= 2)
        inventory->drug_time += game->delta_time;
    if (inventory->drug_time > 10.0 && inventory->drug_object == 0) {
        player->speed /= 500.0;
        inventory->drug_object = 2;
        inventory->drug_time = 0.0;
    }
    if (inventory->drug_time > 10.0 && inventory->drug_object == 1) {
        player->damage_reduction -= 50;
        player->speed *= 4.0;
        inventory->drug_object = -1;
    }
    if (inventory->drug_time > 5.0 && inventory->drug_object == 2) {
        player->speed *= 250.0;
        inventory->drug_object = -1;
    }
    return 0;
}

int manage_drug_adiction(game_t *game, inventory_t *inventory,
player_t *player)
{
    inventory->crack_time += game->delta_time;
    if (inventory->crack_time > 1.0) {
        inventory->crack_time = 0.0;
        player->health -= inventory->crake_addiction;
    }
    if (inventory->drug_object == 13) {
        inventory->drug_object = 0;
        player->speed *= 2;
    }
    if (inventory->drug_object == 14) {
        player->damage_reduction += 50;
        player->speed /= 4.0;
        inventory->drug_object = 1;
    }
    if (inventory->drug_object == 15) {
        player->health = 100;
        inventory->crake_addiction += 1;
        inventory->drug_object = -1;
    }
    return manage_drug_malus(game, inventory, player);
}
