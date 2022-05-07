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

int display_guns(game_t *game, player_t *player, int is_destruct)
{
    static char *nbr_bullets = NULL;
    static int old_nbr_bullets = 0;
    sfVector2f nbr_life_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {1700, 900}, game->view);

    if (old_nbr_bullets != player->weapon->ammo) {
        free(nbr_bullets);
        old_nbr_bullets = player->weapon->ammo;
        nbr_bullets = tranform_in_str(player->weapon->ammo);
    }
    if (is_destruct) {
        free(nbr_bullets);
        return 0;
    }
    sfText_setCharacterSize(game->text, 20);
    sfText_setString(game->text, nbr_bullets);
    sfText_setPosition(game->text, nbr_life_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}

int display_health(game_t *game, player_t *player, int is_destruct)
{
    static char *nbr_life = NULL;
    static float old_nbr_life = 0;
    sfVector2f nbr_life_pos = sfRenderWindow_mapPixelToCoords(game->window,
    (sfVector2i) {10, 10}, game->view);

    if (old_nbr_life != player->health) {
        free(nbr_life);
        old_nbr_life = player->health;
        nbr_life = tranform_in_str((int)player->health);
    }
    if (is_destruct) {
        free(nbr_life);
        return 0;
    }
    sfText_setCharacterSize(game->text, 20);
    sfText_setString(game->text, nbr_life);
    sfText_setPosition(game->text, nbr_life_pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    return 0;
}

int display(game_t *game, player_t *player)
{
    display_map_sprite(game);
    if (game->debug)
        enemy_debug(game, player);
    draw_framebuffer(game);
    display_enemies(game);
    display_bullets(game->bullets, game);
    display_player(game, player);
    display_all_npc(game);
    display_health(game, player, 0);
    display_guns(game, player, 0);
    enemy_actions(game, player);
    sfRenderWindow_display(game->window);
    return 0;
}

int verify_win(game_t *game, player_t *player)
{
    enemy_t **all_enemies = game->levels[game->current_level]->enemies;
    int nbr_alive = 0;

    if (player->health < 1.0) {
        game->scene = Quit;
        write(1, "T'ES NUL\n", 9);
    }
    for (int i = 0; all_enemies[i]; i++) {
        if (all_enemies[i]->health > 0)
            nbr_alive++;
    }
    if (nbr_alive == 0) {
        game->scene = Quit;
        write(1, "T'AS GAGNE\n", 11);
    }
}

static int update_level_xp(player_t *player)
{
    if (player->xp > 10 * player->level) {
        player->xp -= 10 * player->level;
        player->level++;
        player->speed += 30;
        player->damage_reduction += 5;
        player->crit_rate += 10;
    }
}

static int manage_player(game_t *game, player_t *player)
{
    update_level_xp(player);
    move_player(game, player);
    fill_mouse(game, player);
    return 0;
}

int game(game_t *game, player_t *player, sfEvent event)
{
    stop_music(game->sounds->all_musics[1]);
    play_music(game->sounds->all_musics[0]);
    while (game->scene == Game) {
        update_clock(game);
        view_update(game, player);
        particle_update(game);
        sfRenderWindow_clear(game->window, sfBlack);
        npc_event(game, player);
        manage_bullet(game, player);
        manage_player(game, player);
        get_game_event(game, &event, player);
        
        display(game, player);
        verify_win(game, player);
    }
    return 0;
}
