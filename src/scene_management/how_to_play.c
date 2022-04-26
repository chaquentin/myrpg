/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** how_to_play
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

button_t **create_menu_button(game_t *game)
{
    button_t **button = malloc(16);

    if (!button)
        return NULL;
    button[0] = create_button(LArrow1, game, Menu);
    button[1] = NULL;
    return button;
}

button_t **create_languages_button(game_t *game)
{
    button_t **languages_button = malloc(sizeof(button_t *) * 3);

    if (!languages_button)
        return NULL;
    languages_button[0] = create_button(LArrow1, game, Help);
    languages_button[1] = create_button(RArrow1, game, Help);
    languages_button[2] = NULL;
    languages_button[0]->pos = (sfVector2f) {200, 500};
    languages_button[1]->pos = (sfVector2f) {900, 500};
    return languages_button;
}

sfSound *create_sound(game_t *game)
{
    sfSound *sound = sfSound_create();

    if (!sound)
        return NULL;
    sfSound_setVolume(sound, 100);
    sfSound_setBuffer(sound, game->sounds->all_buffer[0]);
    game->sounds->sound_vol = 100;
    sfSound_setLoop(sound, sfTrue);
    sfSound_play(sound);
    return sound;
}

int help(game_t *game, player_t *player, sfEvent event)
{
    sprite_t *background = create_sprite("asset/back.png");
    button_t **button = create_menu_button(game);
    button_t **languages_button = create_languages_button(game);
    sfSound *sound = create_sound(game);

    if (!background || !button || !sound)
        game->scene = Quit;
    while (game->scene == Help) {
        get_event(game, &event ,button);
        sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
        display_button(button, game);
        display_button(languages_button, game);
        sfRenderWindow_display(game->window);
    }
    sfSound_stop(sound);
    sfSound_destroy(sound);
    destroy_button(button);
    destroy_sprite(background);
    return 0;
}
