/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** menu_management
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static int get_option_event(game_t *game, sfEvent *event, button_t **all_button)
{
    manage_mouse(game, event, all_button);
    while(sfRenderWindow_pollEvent(game->window, event))
        if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = Quit;
        else if (event->type == sfEvtMouseButtonReleased)
            manage_released(game, all_button);
}

button_t **init_menu_buton(game_t *game)
{
    button_t **button = NULL;
    int nbr_button = 4;
    sfVector2f pos[4] = {{750, 150}, {750, 400}, {500, 700}, {1000, 700}};

    button = malloc(sizeof(button_t) * nbr_button + 1);
    if (button == NULL)
        return (NULL);
    button[nbr_button] = NULL;
    button[0] = create_button(Play1, game, Game);
    button[1] = create_button(Settings1, game, Option);
    button[2] = create_button(How1, game, Help);
    button[3] = create_button(Exit1, game, Quit);
    for (int i = 0; i < nbr_button; i++) {
        button[i]->pos = pos[i];
    }
    return button;
}

int menu(game_t *game, player_t *player, sfEvent event)
{
    button_t **button = NULL;
    sprite_t *mexicano = create_sprite("asset/back.png");

    button = init_menu_buton(game);
    if (button == NULL || !mexicano)
        game->scene = Quit;
    while (game->scene == Menu) {
        get_option_event(game, &event , button);
        sfRenderWindow_drawSprite(game->window, mexicano->sprite, NULL);
        display_button(button, game);
        sfRenderWindow_display(game->window);
    }
    destroy_sprite(mexicano);
    return destroy_button(button);
}
