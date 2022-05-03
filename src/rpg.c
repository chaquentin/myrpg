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
    game_t *game = create_game((ac >= 2 && !my_strcmp(av[1], "-d")));
    int error = 0;

    srand((long) &error);
    if (!game)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, game->framerate_limit);
    manage_scene(game);
    destroy_game(game);
    return error;
}
