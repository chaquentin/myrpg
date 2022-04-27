/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_help
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

button_t **create_help_button(game_t *game)
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
    languages_button[1]->pos = (sfVector2f) {1500, 500};
    return languages_button;
}

sfSound *create_help_sound(game_t *game)
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

int init_help_sprite(sfSprite *sprite, sfSprite *box)
{
    sfSprite_setPosition(sprite, (sfVector2f) {660, 300});
    sfSprite_setScale(sprite, (sfVector2f) {10, 10});
    sfSprite_setScale(box, (sfVector2f) {2, 2});
    sfSprite_setPosition(box, (sfVector2f) {450, 50});
}

int destroy_help(sprite_t *background, button_t **scene_button,
button_t **languages_button, sfSound *sound)
{
    sfSound_stop(sound);
    sfSound_destroy(sound);
    destroy_button(languages_button);
    destroy_button(scene_button);
    destroy_sprite(background);
    return 0;
}
