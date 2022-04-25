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

static int manage_mouse(game_t *game, sfEvent *event, button_t **all_button, int nbr_button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f fmouse = (sfVector2f) {mouse.x, mouse.y};

    for (int i = 0; i < nbr_button; i++) {
        manage_click(all_button[i], fmouse, game);
    }
}

static int manage_released(game_t *game, button_t **all_button, int nbr_button)
{
    for (int i = 0; i < nbr_button; i++) {
        if (all_button[i]->state == 1)
            game->scene = all_button[i]->next_scene;
    }
}

static void get_event(game_t *game, sfEvent *event, button_t **all_button,
int nbr_button)
{
    manage_mouse(game, event, all_button, nbr_button);
    while(sfRenderWindow_pollEvent(game->window, event))
        if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            game->scene = Quit;
        else if (event->type == sfEvtMouseButtonReleased)
            manage_released(game, all_button, nbr_button);
}

button_t **init_menu_buton(game_t *game, int nbr_button)
{
    button_t **button = NULL;
    sfVector2f pos[4] = {{750, 150}, {750, 400}, {500, 700}, {1000, 700}};

    button = malloc(sizeof(button_t) * nbr_button);
    if (button == NULL)
        return (NULL);
    button[0] = create_button(Play1, game, Game);
    button[1] = create_button(Settings1, game, Option);
    button[2] = create_button(How1, game, Help);
    button[3] = create_button(Exit1, game, Quit);

    for (int i = 0; i < nbr_button; i++) {
        button[i]->pos = pos[i];
    }
    return button;
}

int display_button(button_t **button, int nbr_button, game_t *game)
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {2, 2};

    for (int i = 0; i < nbr_button; i++) {
        scale.x = 3;
        scale.y = 3;
        pos = button[i]->pos;
        sfSprite_setScale(button[i]->sprite, scale);
        sfSprite_setPosition(button[i]->sprite, pos);
        sfRenderWindow_drawSprite(game->window, button[i]->sprite, NULL);
        scale.x = 1;
        scale.y = 1;
        sfSprite_setScale(button[i]->sprite, scale);
    }
}

int destroy_button(button_t **button, int size)
{
    if (!button)
        return 84;
    for (int i = 0; i < size; i++)
        free(button[i]);
    free(button);
    return 0;
}

int destroy_sprite(sprite_t *sprite)
{
    if (!sprite)
        return 84;
    if (sprite->sprite)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture)
        sfTexture_destroy(sprite->texture);
    free(sprite);
    return 0;
}

sprite_t *create_sprite(char *path)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (!sprite)
        return NULL;
    sprite->texture = sfTexture_createFromFile(path, NULL);
    if (!sprite->texture) {
        destroy_sprite(sprite);
        return NULL;
    }
    sprite->sprite = sfSprite_create();
    if (!sprite->sprite) {
        destroy_sprite(sprite);
        return NULL;
    }
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->pos = (sfVector2f) {0, 0};
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return sprite;
}

int menu(game_t *game, player_t *player, sfEvent event)
{
    int nbr_button = 4;
    button_t **button = NULL;
    sprite_t *mexicano = create_sprite("asset/gang.jpg");

    button = init_menu_buton(game, nbr_button);
    if (button == NULL || !mexicano)
        game->scene = Quit;
    while (game->scene == Menu) {
        get_event(game, &event , button, nbr_button);
        sfRenderWindow_drawSprite(game->window, mexicano->sprite, NULL);
        display_button(button, nbr_button, game);
        sfRenderWindow_display(game->window);
    }
    destroy_sprite(mexicano);
    return destroy_button(button, nbr_button);
}

int option(game_t *game, player_t *player, sfEvent event)
{
    sprite_t *mexicano = create_sprite("asset/gang.jpg");
    sfSprite *sprite = game->all_sprite[Decor][OptionGround];
    button_t **button = malloc(8);

    button[0] = create_button(LArrow1, game, Menu);
    sfSprite_setPosition(sprite, (sfVector2f) {300, 50});
    sfSprite_setScale(sprite, (sfVector2f) {2, 2});
    while (game->scene == Option) {
        get_event(game, &event ,button, 1);
        sfRenderWindow_drawSprite(game->window, mexicano->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
        display_button(button, 1, game);
        sfRenderWindow_display(game->window);
    }
    destroy_sprite(mexicano);
    return 0;
}

int pause(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL, 0);
    return 0;
}

int win(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL, 0);
    return 0;
}

int help(game_t *game, player_t *player, sfEvent event)
{
    get_event(game, &event, NULL, 0);
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
