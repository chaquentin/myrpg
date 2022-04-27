/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_option
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static sfVector2f txt_pos[] = {{770, 190}, {770, 430}, {900, 700},
{900, 300}, {900, 520}, {900, 800}};

static char *tranform_in_str(int nbr)
{
    char *str = malloc(sizeof(char) * 4);

    str[0] = nbr / 100 + '0';
    nbr -= (nbr / 100) * 100;
    str[1] = nbr / 10 + '0';
    nbr -= (nbr / 10) * 10;
    str[2] = nbr + '0';
    str[3] = '\0';
    return str;
}

static int add_option_txt(game_t *game, text_option_t *option_txt)
{
    option_txt->txt[0] = "Music volume";
    option_txt->txt[1] = "Sound volume";
    option_txt->txt[2] = "FPS";
    option_txt->txt[3] = tranform_in_str(game->sounds->music_vol);
    option_txt->txt[4] = tranform_in_str(game->sounds->sound_vol);
    option_txt->txt[5] = tranform_in_str(game->framerate_limit);
    return 0;
}

text_option_t *create_option(game_t *game)
{
    text_option_t *option_txt = NULL;

    option_txt = malloc(sizeof(text_option_t));
    if (option_txt == NULL)
        return (NULL);
    add_option_txt(game, option_txt);
    option_txt->text = sfText_create();
    option_txt->font = sfFont_createFromFile("asset/Team 401.ttf");
    if (option_txt->text == NULL || option_txt->font == NULL)
        return (NULL);
    sfText_setFont(option_txt->text, option_txt->font);
    sfText_setCharacterSize(option_txt->text, 30);
    option_txt->framerate_limit = game->framerate_limit;
    option_txt->music_vol = game->sounds->music_vol;
    option_txt->sound_vol = game->sounds->sound_vol;
    return (option_txt);
}

int update_text(text_option_t *option_txt, game_t *game)
{
    if (option_txt->music_vol != game->sounds->music_vol) {
        free(option_txt->txt[3]);
        option_txt->txt[3] = tranform_in_str(game->sounds->music_vol);
        option_txt->music_vol = game->sounds->music_vol;
    }
    if (option_txt->sound_vol != game->sounds->sound_vol) {
        free(option_txt->txt[4]);
        option_txt->txt[4] = tranform_in_str(game->sounds->sound_vol);
        option_txt->sound_vol = game->sounds->sound_vol;
    }
    if (option_txt->framerate_limit != game->framerate_limit) {
        free(option_txt->txt[5]);
        option_txt->txt[5] = tranform_in_str(game->framerate_limit);
        option_txt->framerate_limit = game->framerate_limit;
    }
}

int display_option(game_t *game, button_t **scene_button,
button_t **option_button, text_option_t *option_txt)
{
    for (int i = 0; i < 6; i++) {
        sfText_setString(option_txt->text, option_txt->txt[i]);
        sfText_setPosition(option_txt->text, txt_pos[i]);
        sfRenderWindow_drawText(game->window, option_txt->text, NULL);
    }
    display_button(option_button, game);
    display_button(scene_button, game);
    sfRenderWindow_display(game->window);
}
