/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_scene
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

int option(game_t *game, player_t *player, sfEvent event)
{
    sprite_t *mexicano = create_sprite("asset/back.png");
    sfSprite *sprite = game->all_sprite[Decor][OptionGround];
    button_t **button = malloc(16);

    button[0] = create_button(LArrow1, game, Menu);
    button[1] = NULL;
    sfSprite_setPosition(sprite, (sfVector2f) {300, 50});
    sfSprite_setScale(sprite, (sfVector2f) {2, 2});
    while (game->scene == Option) {
        get_event(game, &event ,button);
        sfRenderWindow_drawSprite(game->window, mexicano->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        display_button(button, game);
        sfRenderWindow_display(game->window);
    }
    destroy_button(button);
    destroy_sprite(mexicano);
    return 0;
}

int pause(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL);
    return 0;
}

int win(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL);
    return 0;
}

int help(game_t *game, player_t *player, sfEvent event)
{
    sprite_t *background = create_sprite("asset/back.png");
    button_t **button = malloc(16);

    button[0] = create_button(LArrow1, game, Menu);
    button[1] = NULL;
    while (game->scene == Help) {
        get_event(game, &event ,button);
        sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
        display_button(button, game);
        sfRenderWindow_display(game->window);
    }
    destroy_button(button);
    destroy_sprite(background);
    return 0;
}

static const int (*game_function[])(game_t *, player_t *, sfEvent) = {&menu,
&game, &option, &pause, &win, &help};

int manage_scene(game_t *game)
{
    int error_code = 0;
    player_t *player = NULL;
    sfEvent event;

    player = create_player(game);
    if (!player)
        return 84;
    while (game->scene != Quit) {
        error_code = game_function[game->scene - 1](game, player, event);
    }
    destroy_player(player);
    return 0;
}
