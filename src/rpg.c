/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** rpg
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "prototype.h"

int main(int ac, char **av)
{
    game_t *game = create_game();
    player_t *player = NULL;
    int error = 0;

    if (!game)
        return 84;
    player = create_player(game);
    if (!player)
        error = 84;
    else {
        start_game(game, player);
        free(player);
    }
    destroy_game(game);
    return error;
}
