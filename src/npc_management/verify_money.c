/*
** EPITECH PROJECT, 2022
** rpg_test
** File description:
** verify_money
*/

#include "prototype.h"
#include "structure.h"

int stop_player(player_t *player)
{
    for (int i = 0; i < 4; i++)
        player->movement[i] = 0;
    return (0);
}

int verify_money(player_t *player, game_t *game)
{
    stop_player(player);
    if (player->money < 50)
        return write_dialogue(game, "Mais tu es pauvre", player);
    if (write_dialogue(game,
    game->all_npc[Matthias - Antonin]->all_dialogs[0], player) == 1)
        return 1;
    player->money -= 50;
    for (int i = 12; i != 23; i++)
        sfSprite_scale(game->all_sprite[Weapon][i], (sfVector2f) {3, 3});
    return 0;
}
