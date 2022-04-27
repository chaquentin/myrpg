/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** option_management
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

static int get_option_event(game_t *game, sfEvent *event,
button_t **scene_button, button_t **option_button)
{
    manage_mouse(game, event, scene_button);
    manage_mouse(game, event, option_button);
    while (sfRenderWindow_pollEvent(game->window, event))
        scene_button_management(game, event, scene_button);
        option_button_management(game, event, option_button);
}

button_t **create_option_button(game_t *game)
{
    button_t **option_button = malloc(sizeof(button_t *) * 2);

    option_button[0] = create_button(LArrow1, game, Menu);
    option_button[1] = NULL;
    return (option_button);
}

button_t **create_update_button(game_t *game)
{
    button_t **update_button = malloc(sizeof(button_t) * (7));
    static const sfVector2f pos[6] = {{600, 200}, {1170, 200}, {600, 460},
    {1170, 460}, {600, 720}, {1170, 720}};

    update_button[0] = create_button(LArrow1, game, Option);
    update_button[1] = create_button(RArrow1, game, Option);
    update_button[2] = create_button(LArrow1, game, Menu);
    update_button[3] = create_button(RArrow1, game, Menu);
    update_button[4] = create_button(LArrow1, game, Game);
    update_button[5] = create_button(RArrow1, game, Game);
    update_button[6] = NULL;
    for (int i = 0; i < 6; i++)
        update_button[i]->pos = pos[i];
    return (update_button);
}

int destroy_text_option(text_option_t *option_txt)
{
    if (option_txt == NULL)
        return (84);
    if (option_txt->font)
        sfFont_destroy(option_txt->font);
    if (option_txt->text)
        sfText_destroy(option_txt->text);
    free(option_txt->txt[3]);
    free(option_txt->txt[4]);
    free(option_txt->txt[5]);
    free(option_txt);
    return 0;
}

int destroy_option(sprite_t *sprite, text_option_t *option,
button_t **option_button, button_t **scene_button)
{
    destroy_text_option(option);
    destroy_button(option_button);
    destroy_button(scene_button);
    destroy_sprite(sprite);
    return 0;
}

int option(game_t *game, player_t *player, sfEvent event)
{
    sprite_t *mexicano = create_sprite("asset/back.png");
    sfSprite *sprite = game->all_sprite[Decor][OptionGround];
    button_t **button = create_option_button(game);
    button_t **option_button = create_update_button(game);
    text_option_t *option = create_option(game);

    if (!mexicano || !sprite || !button || !option_button || !option)
        game->scene = Quit;
    sfSprite_setPosition(sprite, (sfVector2f) {450, 50});
    sfSprite_setScale(sprite, (sfVector2f) {2, 2});
    while (game->scene == Option) {
        get_option_event(game, &event, button, option_button);
        update_text(option, game);
        sfRenderWindow_drawSprite(game->window, mexicano->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        display_option(game, button, option_button, option);
    }
    destroy_option(mexicano, option, button, option_button);
    return 0;
}
