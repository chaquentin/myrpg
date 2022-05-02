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
    if (game->view)
        sfView_destroy(game->view);
    if (game->text)
        sfText_destroy(game->text);
    if (game->font)
        sfFont_destroy(game->font);
    destroy_all_bullet(game->all_bullets);
    destroy_levels(game->levels);
    destroy_sounds(game->sounds);
    free(game);
}

sfSprite ***create_all_sprites(sfTexture *texture)
{
    sfSprite ***all_sprite = malloc(sizeof(sfSprite **) * (NBR_CAT + 1));

    if (!all_sprite)
        return NULL;
    all_sprite[0] = create_all_sprite(NBR_DECOR, decor_rect, texture);
    all_sprite[1] = create_all_sprite(NBR_WALL, wall_rect, texture);
    all_sprite[2] = create_all_sprite(NBR_PLAYER, player_rect, texture);
    all_sprite[3] = create_all_sprite(NBR_SHIRT, shirt_rect, texture);
    all_sprite[4] = create_all_sprite(NBR_HAT, hat_rect, texture);
    all_sprite[5] = create_all_sprite(NBR_PANTS, pants_rect, texture);
    all_sprite[6] = create_all_sprite(NBR_WEAPON, weapon_rect, texture);
    all_sprite[7] = create_all_sprite(NBR_ENEMIES, enemies_rect, texture);
    all_sprite[8] = create_all_sprite(NBR_BUTTON, button_rect, texture);
    all_sprite[9] = NULL;
    for (int i = 0; i < NBR_CAT; i++)
        if (!all_sprite[i]) {
            destroy_all_sprites(all_sprite);
            return NULL;
        }
    return all_sprite;
}

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = NULL;

    window = sfRenderWindow_create(mode, "Niggay land", sfClose , NULL);
    sfRenderWindow_setFramerateLimit(window, 144);
    if (window == NULL)
        return NULL;
    return window;
}

static int init_game_parameters(game_t *game, int debug)
{
    game->debug = debug;
    game->scene = Menu;
    game->framerate_limit = 144;
    game->window = create_window();
    game->texture = sfTexture_createFromFile(SPRITESHEET_PATH, NULL);
    game->delta_time = 0.0;
    game->clock = sfClock_create();
    game->sounds = create_all_sounds();
    game->text = sfText_create();
    game->font = sfFont_createFromFile("asset/Team 401.ttf");
    game->all_bullets = init_list();
    return 0;
}

game_t *create_game(int debug)
{
    game_t *game = NULL;

    game = malloc(sizeof(game_t));
    if (!game)
        return NULL;
    init_game_parameters(game, debug);
    if (!game->window || !game->texture || !game->sounds || !game->text ||
    !game->font) {
        destroy_game(game);
        return NULL;
    }
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 50);
    game->all_sprite = create_all_sprites(game->texture);
    if (!game->all_sprite) {
        destroy_game(game);
        return NULL;
    }
    game->levels = create_levels(LEVEL_PATH, game);
    game->current_level = 0;
    game->view = create_view(game, game->debug);
    return game;
}
