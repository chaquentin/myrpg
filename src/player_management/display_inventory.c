/*
** EPITECH PROJECT, 2022
** rpg_test
** File description:
** display_inventory
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
    sfText_setCharacterSize(game->text, 100);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    pos.y += 160;
    display_bag(game, player->inventory[0].fst_object, pos);
    pos.x += 160;
    display_bag(game, player->inventory[0].snd_object, pos);
    pos.x += 160;
    display_bag(game, player->inventory[0].trd_object, pos);
    return (0);
}

int display_stat(game_t *game, player_t *player)
{
    sfVector2f pos = {100, 100};

    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->view);
    sfText_setCharacterSize(game->text, 50);
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
