/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** get_global_event
*/

#include "structure.h"

int verify_colision(button_t *object,
sfVector2f mouse_pos, game_t *game)
{
    sfVector2f obj_pos = object->pos;

    if (obj_pos.x < mouse_pos.x &&
    mouse_pos.x < obj_pos.x + 384 &&
    obj_pos.y < mouse_pos.y &&
    mouse_pos.y < obj_pos.y + 192) {
        return 1;
    }
    return 0;
}

int manage_click(button_t *object, sfVector2f mouse_pos, game_t *game)
{
    int is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    int is_collision = verify_colision(object, mouse_pos, game);
    int state = 0;

    if (is_collision && is_pressed)
        state = 2;
    else if (is_collision)
        state = 1;
    else
        state = 0;
    object->sprite = game->all_sprite[Button][state + object->status];
    object->state = state;
    return 0;
}

int manage_mouse(game_t *game, sfEvent *event, button_t **all_button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f fmouse = (sfVector2f) {mouse.x, mouse.y};

    for (int i = 0; all_button[i]; i++) {
        manage_click(all_button[i], fmouse, game);
    }
}

int manage_released(game_t *game, button_t **all_button)
{
    for (int i = 0; all_button[i]; i++) {
        if (all_button[i]->state == 1)
            game->scene = all_button[i]->next_scene;
    }
}

void get_event(game_t *game, sfEvent *event, button_t **all_button)
{
    manage_mouse(game, event, all_button);
    while(sfRenderWindow_pollEvent(game->window, event))
        if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = Quit;
        else if (event->type == sfEvtMouseButtonReleased)
            manage_released(game, all_button);
        // manage_spec_scene(game->scene);
}
