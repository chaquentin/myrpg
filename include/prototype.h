/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
    #define PROTOTYPE_H_

    #include "structure.h"

    game_t *create_game(void);
    void destroy_game(game_t *game);
    player_t *create_player(game_t *game);
    int start_game(game_t *game, player_t *player);
    void display_player(game_t *game, player_t *player);
    void fill_mouse(game_t *game, player_t *player);
    int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player);
    int manage_key_released(sfKeyCode key_code, player_t *player);
    void move_player(game_t *game, player_t *player);

#endif
