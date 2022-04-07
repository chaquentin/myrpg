/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** window_creation
*/

#include <stdlib.h>
#include "structure.h"

void destroy_game(game_t *game)
{
    if (game->window)
        sfRenderWindow_destroy(game->window);
    if (game->texture)
        sfTexture_destroy(game->texture);
    if (game->all_sprite) {
        for (int i = 0; game->all_sprite[i]; i++)
            sfSprite_destroy(game->all_sprite[i]);
        free(game->all_sprite);
    }
    if (game->clock)
        sfClock_destroy(game->clock);
    free(game);
}

sfSprite **create_sprites(sfTexture *texture)
{
    sfSprite **all_sprites = malloc(sizeof(sfSprite *) * (ALL_SPRITES + 1));

    if (!all_sprites)
        return NULL;
    for (int i = 0; i < ALL_SPRITES; i++) {
        all_sprites[i] = sfSprite_create();
        if (!all_sprites[i]) {
            all_sprites[i] = NULL;
            return NULL;
        }
        sfSprite_setTexture(all_sprites[i], texture, sfFalse);
        sfSprite_setTextureRect(all_sprites[i], all_rect[i]);
    }
    all_sprites[ALL_SPRITES] = NULL;
    return all_sprites;
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
    game->all_sprite = create_sprites(game->texture);
    if (!game->all_sprite) {
        destroy_game(game);
        return NULL;
    }
    return game;
}
