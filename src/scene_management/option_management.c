/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** option_management
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

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
