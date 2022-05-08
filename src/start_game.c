/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** start_game
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototype.h"
#include "structure.h"

static int manage_mouse_click(sfEvent *event, player_t *player)
{
    if (event->type == sfEvtMouseButtonPressed &&
    event->mouseButton.button == sfMouseLeft)
        player->is_clicked = sfTrue;
    if (event->type == sfEvtMouseButtonReleased &&
    event->mouseButton.button == sfMouseLeft)
        player->is_clicked = sfFalse;
}

static void get_game_event(game_t *game, sfEvent *event, player_t *player)
{
    shoot(game, player, 0);
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed)
            manage_key_pressed(game, event->key.code, player);
        if (event->type == sfEvtKeyReleased)
            manage_key_released(event->key.code, player);
        manage_mouse_click(event, player);
    }
    if (player->is_clicked && player->weapon->ammo > 0)
        shoot(game, player, 1);
}

int update_clock(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float seconds = time.microseconds / 1000000.0;
    static float old_seconds = 0.0;

    game->delta_time = seconds - old_seconds;
    old_seconds = seconds;
    if (seconds > 10) {
        sfClock_restart(game->clock);
        old_seconds = 0.0;
    }
    return (0);
}

int verify_win(game_t *game, player_t *player)
{
    enemy_t **all_enemies = game->levels[0]->enemies;
    int nbr_alive = 0;

    if (player->health < 1.0) {
        game->scene = Quit;
        write(1, "T'ES NUL\n", 9);
    }
    for (int i = 0; all_enemies[i]; i++) {
        if (all_enemies[i]->health > 0)
            nbr_alive++;
    }
    if (nbr_alive == 0)
        game->scene = Win;
    return (0);
}

int manage_drug_malus(game_t *game, inventory_t *inventory,
player_t *player)
{
    if (inventory->drug_object >= 0 && inventory->drug_object <= 2)
        inventory->drug_time += game->delta_time;
    if (inventory->drug_time > 10.0 && inventory->drug_object == 0) {
        player->speed /= 500.0;
        inventory->drug_object = 2;
        inventory->drug_time = 0.0;
    }
    if (inventory->drug_time > 10.0 && inventory->drug_object == 1) {
        player->damage_reduction -= 50;
        player->speed *= 4.0;
        inventory->drug_object = -1;
    }
    if (inventory->drug_time > 5.0 && inventory->drug_object == 2) {
        player->speed *= 250.0;
        inventory->drug_object = -1;
    }
    return 0;
}

int manage_drug_adiction(game_t *game, inventory_t *inventory,
player_t *player)
{
    inventory->crack_time += game->delta_time;
    if (inventory->crack_time > 1.0) {
        inventory->crack_time = 0.0;
        player->health -= inventory->crake_addiction;
    }
    if (inventory->drug_object == 13) {
        inventory->drug_object = 0;
        player->speed *= 2;
    }
    if (inventory->drug_object == 14) {
        player->damage_reduction += 50;
        player->speed /= 4.0;
        inventory->drug_object = 1;
    }
    if (inventory->drug_object == 15) {
        player->health = 100;
        inventory->crake_addiction += 1;
        inventory->drug_object = -1;
    }
    return manage_drug_malus(game, inventory, player);
}

int game(game_t *game, player_t *player, sfEvent event)
{
    stop_music(game->sounds->all_musics[1]);
    play_music(game->sounds->all_musics[0]);
    sfView_setSize(game->view, (sfVector2f) {960, 540});
    while (game->scene == Game) {
        change_level(game, player);
        update_clock(game);
        get_game_event(game, &event, player);
        view_update(game, player);
        particle_update(game);
        sfRenderWindow_clear(game->window, sfBlack);
        manage_drug_adiction(game, player->inventory, player);
        npc_event(game, player);
        manage_bullet(game, player);
        manage_player(game, player);
        display_game(game, player);
        verify_win(game, player);
    }
    return 0;
}
