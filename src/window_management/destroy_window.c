/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** destroy_window
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

static int destroy_game_verification(game_t *game)
{
    if (game->window)
        sfRenderWindow_destroy(game->window);
    if (game->texture)
        sfTexture_destroy(game->texture);
    if (game->all_sprite)
        destroy_all_sprites(game->all_sprite);
    if (game->clock)
        sfClock_destroy(game->clock);
    if (game->view)
        sfView_destroy(game->view);
    if (game->text)
        sfText_destroy(game->text);
    if (game->font)
        sfFont_destroy(game->font);
    if (game->particle)
        free(game->particle);
    return 0;
}

int destroy_game(game_t *game)
{
    if (!game)
        return 84;
    destroy_game_verification(game);
    framebuffer_destroy(game);
    destroy_all_npc(game->all_npc);
    destroy_levels(game->levels);
    destroy_sounds(game->sounds);
    destroy_all_bullet(game->bullets);
    free(game);
}
