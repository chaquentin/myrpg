/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** manage_option_button
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static int fps[] = {15, 30, 60, 120, 144, 160, 240};

int scene_button_management(game_t *game, sfEvent *event,
button_t **scene_button)
{
    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = Quit;
    else if (event->type == sfEvtMouseButtonReleased)
        manage_released(game, scene_button);
}

static int manage_fps(game_t *game, button_t *button)
{
    int fps_index = 0;

    for (; fps[fps_index] != game->framerate_limit; fps_index++);
    if (button->status == LArrow1)
        fps_index -= (fps_index == 0) ? 0 : 1;
    else if (button->status == RArrow1)
        fps_index += (fps_index == 6) ? 0 : 1;
    game->framerate_limit = fps[fps_index];
    sfRenderWindow_setFramerateLimit(game->window, game->framerate_limit);
    return 0;
}

static int update_option_click(game_t *game, sfEvent *event,
button_t **button, int i)
{
    if (button[i]->is_click == 1 && event->type == sfEvtMouseButtonReleased) {
        switch (button[i]->next_scene) {
            case Option:
            game->sounds->music_vol += (button[i]->status == LArrow1) ? -5 : 5;
            break;
            case Menu:
            game->sounds->sound_vol += (button[i]->status == LArrow1) ? -5 : 5;
            break;
            case Game:
            manage_fps(game, button[i]);
            break;
            default:
            break;
        }
        button[i]->is_click = 0;
    }
    return 0;
}

static int option_button_management(game_t *game, sfEvent *event,
button_t **button)
{

    for (int i = 0; button[i]; i++) {
        update_option_click(game, event, button, i);
    }
    if (game->sounds->music_vol > 100)
        game->sounds->music_vol = 100;
    if (game->sounds->music_vol < 0)
        game->sounds->music_vol = 0;
    if (game->sounds->sound_vol > 100)
        game->sounds->sound_vol = 100;
    if (game->sounds->sound_vol < 0)
        game->sounds->sound_vol = 0;
    for (int i = 0; game->sounds->all_musics[i]; i++)
        sfMusic_setVolume(game->sounds->all_musics[i],
        game->sounds->music_vol);
    return 0;
}

int get_option_event(game_t *game, sfEvent *event,
button_t **scene_button, button_t **option_button)
{
    manage_mouse(game, event, scene_button);
    manage_mouse(game, event, option_button);
    while (sfRenderWindow_pollEvent(game->window, event))
        scene_button_management(game, event, scene_button);
        option_button_management(game, event, option_button);
}
