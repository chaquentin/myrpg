/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** how_to_play
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static int language_button_management(game_t *game, sfEvent *event,
button_t **languages_button)
{
    int language_index = game->debug;

    if (languages_button[0]->is_click == 1 &&
    event->type == sfEvtMouseButtonReleased) {
        language_index -= 1;
        languages_button[0]->is_click = 0;
    } else if (languages_button[1]->is_click == 1 &&
    event->type == sfEvtMouseButtonReleased) {
        language_index += 1;
        languages_button[1]->is_click = 0;
    }
    if (language_index < 0)
        language_index = Arabe - Chinese;
    if (language_index > Arabe - Chinese)
        language_index = 0;
    game->debug = language_index;
    return 0;
}

static int get_how_event(game_t *game, sfEvent *event,
button_t **scene_button, button_t **languages_button)
{
    manage_mouse(game, event, scene_button);
    manage_mouse(game, event, languages_button);
    while (sfRenderWindow_pollEvent(game->window, event))
        scene_button_management(game, event, scene_button);
        language_button_management(game, event, languages_button);
}

static int display_help(game_t *game, button_t **button,
button_t **languages_button, sfSprite *sprite)
{
    display_button(button, game);
    display_button(languages_button, game);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_display(game->window);
}

static int update_flag_sound(game_t *game, sfSound *sound,
sfSprite **sprite)
{
    static int sound_index = 0;

    if (sound_index != game->debug) {
        sfSound_setBuffer(sound, game->sounds->all_buffer[game->debug]);
        sfSound_play(sound);
        sound_index = game->debug;
        *sprite = game->all_sprite[Decor][Chinese + game->debug];
    }
    sfSprite_setPosition(*sprite, (sfVector2f) {660, 300});
    sfSprite_setScale(*sprite, (sfVector2f) {10, 10});
}

int help(game_t *game, player_t *player, sfEvent event)
{
    sprite_t *background = create_sprite("asset/back.png");
    button_t **button = create_help_button(game);
    button_t **languages_button = create_languages_button(game);
    sfSound *sound = create_help_sound(game);
    sfSprite *sprite = game->all_sprite[Decor][Chinese];
    sfSprite *box = game->all_sprite[Decor][HowToPlayGround];

    if (!background || !button || !sound)
        game->scene = Quit;
    else
        init_help_sprite(sprite, box);
    stop_music(game->sounds->all_musics[1]);
    while (game->scene == Help) {
        get_how_event(game, &event, button, languages_button);
        update_flag_sound(game, sound, &sprite);
        sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, box, NULL);
        display_help(game, button, languages_button, sprite);
    }
    return destroy_help(background, button, languages_button, sound);
}
