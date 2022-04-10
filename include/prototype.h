/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
    #define PROTOTYPE_H_

    #include "structure.h"

//===================================GAME====================================//

    game_t *create_game(int debug);
    int start_game(game_t *game, player_t *player);

    void destroy_game(game_t *game);

//==================================PLAYER===================================//

    player_t *create_player(game_t *game);
    int display_player(game_t *game, player_t *player);
    void move_player(game_t *game, player_t *player);
    void fill_mouse(game_t *game, player_t *player);

    int destroy_player(player_t *player);

//================================ACCESSORIES================================//

    clothes_t *create_start_clothes(game_t *game);
    weapon_t *create_start_weapon(game_t *game);

//==================================SPRITES==================================//

    sfSprite **create_sprites(int nbr,
    const sfIntRect rect[nbr], sfTexture *texture);

    int destroy_all_sprites(sfSprite ***sprites);

//====================================MAP====================================//

    char **create_map(char *str);
    sfSprite *create_map_sprite(game_t *game, sfTexture *texture);
    sfVector2f *create_map_corners(char **map);
    sfTexture *create_map_texture(game_t *game, char **map);
    level_t **create_levels(char *path, game_t *game);
    void display_map_sprite(game_t *game);

    void destroy_levels(level_t **level);
    void destroy_map(char **map);
    void destroy_map_corners(sfVector2f *corners);

//=================================ENEMIES==================================//

    enemy_t **enemies_create(char *enemies_data, game_t *game);
    void display_enemies(game_t *game);

    void destroy_enemies(enemy_t **enemies);

//==================================EVENTS===================================//

    int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player);
    int manage_key_released(sfKeyCode key_code, player_t *player);

//===================================WORDS===================================//

    int is_parser(char c, char *to_compare);
    char **my_str_to_word_array(const char *src, char *pars);
    int my_atoi(char *str_ptr);
    int my_putnbr(int nbr, char c);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strdup(const char *src);
    int my_strlen(const char *str);

    void my_free_word_array(char **array);

//===================================VIEW====================================//

    sfView *create_view(game_t *game, int debug);
    void view_update(game_t *game, player_t *player);

    void destroy_view(game_t *game);

#endif
