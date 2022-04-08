/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** window_creation
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

void destroy_game(game_t *game)
{
    if (game->window)
        sfRenderWindow_destroy(game->window);
    if (game->texture)
        sfTexture_destroy(game->texture);
    if (game->all_sprite)
        destroy_all_sprites(game->all_sprite);
    if (game->clock)
        sfClock_destroy(game->clock);
    free(game);
}

sfSprite ***create_all_sprites(sfTexture *texture)
{
    sfSprite ***all_sprite = malloc(sizeof(sfSprite **) * (NBR_CAT + 1));

    if (!all_sprite)
        return NULL;
    all_sprite[0] = create_sprites(NBR_DECOR, decor_rect, texture);
    all_sprite[1] = create_sprites(NBR_WALL, wall_rect, texture);
    all_sprite[2] = create_sprites(NBR_PLAYER, player_rect, texture);
    all_sprite[3] = create_sprites(NBR_SHIRT, shirt_rect, texture);
    all_sprite[4] = create_sprites(NBR_HAT, hat_rect, texture);
    all_sprite[5] = create_sprites(NBR_PANTS, pants_rect, texture);
    all_sprite[6] = create_sprites(NBR_WEAPON, weapon_rect, texture);
    all_sprite[7] = create_sprites(NBR_ENEMIES, enemies_rect, texture);
    all_sprite[8] = NULL;
    for (int i = 0; i < NBR_CAT; i++) {
        if (!all_sprite[i]) {
            destroy_all_sprites(all_sprite);
            return NULL;
        }
    }
    return all_sprite;
}

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = NULL;

    window = sfRenderWindow_create(mode, "Niggay land", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 144);
    if (window == NULL)
        return NULL;
    return window;
}

game_t *create_game(void)
{
    game_t *game = NULL;

    game = malloc(sizeof(game_t));
    if (!game)
        return NULL;
    game->scene = Menu;
    game->framerate_limit = 144;
    game->window = create_window();
    game->texture = sfTexture_createFromFile("asset/sprite_sheet.png", NULL);
    game->delta_time = 0.0;
    game->clock = sfClock_create();
    if (!game->window || !game->texture) {
        destroy_game(game);
        return NULL;
    }
    game->all_sprite = create_all_sprites(game->texture);
    if (!game->all_sprite) {
        destroy_game(game);
        return NULL;
    }
    return game;
}
