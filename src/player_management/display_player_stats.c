/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** display_player_stats
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

static const char *stats[8] = {"Level", "Experience", "Health",
"Critical rate", "Swag", "Damage redution", "Speed", NULL};
static const sfVector2f positions[] = {{500, 100}, {500, 200}, {500, 300},
{500, 400}, {500, 500}, {500, 600}, {500, 700}, {-1, -1}};

static int display_int(game_t *game, int to_display, sfVector2f pos)
{
    char *buff = tranform_in_str(to_display);

    sfText_setString(game->text, buff);
    sfText_setPosition(game->text, pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    free(buff);
    return 0;
}

static int take_drug(enum decor witch_drug, player_t *player)
{
    player->inventory->drug_object = witch_drug;
    player->inventory->drug_time = 0.0;
    player->inventory->nbr_object--;
    return 0;
}

static int use_drug(game_t *game, player_t *player, button_t **button)
{
    if (button[0]->is_click == sfTrue && player->inventory->fst_object != -1 &&
    player->inventory->drug_object == -1) {
        take_drug(player->inventory->fst_object, player);
        player->inventory->fst_object = -1;
    }
    if (button[1]->is_click == sfTrue && player->inventory->snd_object != -1 &&
    player->inventory->drug_object == -1) {
        take_drug(player->inventory->snd_object, player);
        player->inventory->snd_object = -1;
    }
    if (button[2]->is_click == sfTrue && player->inventory->trd_object != -1 &&
    player->inventory->drug_object == -1) {
        take_drug(player->inventory->trd_object, player);
        player->inventory->trd_object = -1;
    }
}

static int get_display_event(game_t *game, sfEvent *event, player_t *player,
button_t **button)
{
    int ret_value = 1;

    manage_mouse(game, event, button);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
        (event->key.code == sfKeyEscape || event->key.code == sfKeyE))
            ret_value = 0;
        if (event->type == sfEvtMouseButtonReleased)
            use_drug(game, player, button);
    }
    return (ret_value);
}

static int display_bag(game_t *game, enum decor inventory, sfVector2f pos)
{
    sfVector2f scale = {2, 2};

    draw_rounded_rectangle(game, (sfIntRect) {pos.x - 5, pos.y - 5, 148,
    138}, 20, (sfColor) {150, 150, 150, 255});
    if (inventory != -1) {
        sfSprite_scale(game->all_sprite[Decor][inventory], scale);
        sfSprite_setPosition(game->all_sprite[Decor][inventory], pos);
        sfRenderWindow_drawSprite(game->window, game->all_sprite[Decor]
        [inventory], NULL);
        scale = (sfVector2f) {0.5, 0.5};
        sfSprite_scale(game->all_sprite[Decor][inventory], scale);
    }
    return (0);
}

static int dispaly_invent(game_t *game, player_t *player)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {1000, 400}, game->view);
    char text[] = "Inventory";

    sfText_setString(game->text, text);
    sfText_setPosition(game->text, pos);
    sfText_setCharacterSize(game->text, 50);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    pos.y += 160;
    display_bag(game, player->inventory[0].fst_object, pos);
    pos.x += 160;
    display_bag(game, player->inventory[0].snd_object, pos);
    pos.x += 160;
    display_bag(game, player->inventory[0].trd_object, pos);
    return (0);
}

static int display_stat(game_t *game, player_t *player)
{
    sfVector2f pos = {100, 100};

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->view);
    sfText_setCharacterSize(game->text, 20);
    for (int i = 0; stats[i]; i++, pos.y += 100) {
        sfText_setString(game->text, stats[i]);
        sfText_setPosition(game->text, pos);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    display_int(game, player->level, positions[0]);
    display_int(game, player->xp, positions[1]);
    display_int(game, (int)player->health, positions[2]);
    display_int(game, player->crit_rate, positions[3]);
    display_int(game, player->swag, positions[4]);
    display_int(game, player->damage_reduction, positions[5]);
    display_int(game, player->speed, positions[6]);
    dispaly_invent(game, player);
    return (0);
}

static button_t **create_invent_button(game_t *game)
{
    button_t **button = malloc(sizeof(button_t *) * 4);
    sfVector2f pos = {1038, 690};

    button[0] = create_button(Select1, game, Game);
    button[0]->pos = pos;
    button[1] = create_button(Select1, game, Game);
    button[1]->pos = (sfVector2f) {pos.x + 160, pos.y};
    button[2] = create_button(Select1, game, Game);
    button[2]->pos = (sfVector2f) {pos.x + 320, pos.y};
    button[3] = NULL;
    return (button);
}

static int display_stats_button(game_t *game, button_t **button)
{
    for (int i = 0; button[i]; i++) {
        sfSprite_setPosition(button[i]->sprite, button[i]->pos);
        sfRenderWindow_drawSprite(game->window, button[i]->sprite, NULL);
    }
    sfRenderWindow_display(game->window);
    return 0;
}

int display_player_stats(game_t *game, player_t *player)
{
    int is_open = 1;
    sfEvent event;
    button_t **button = create_invent_button(game);

    sfView_reset(game->view, (sfFloatRect) {0, 0, 1920, 1080});
    while (is_open) {
        display_stat(game, player);
        is_open = get_display_event(game, &event, player, button);
        display_stats_button(game, button);
        update_clock(game);
    }
    for (int i = 0; i < 4; i++)
        player->movement[i] = 0;
    sfView_setSize(game->view, (sfVector2f) {960, 540});
    return 0;
}
