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
    int display_player(game_t *game, player_t *player);
    void fill_mouse(game_t *game, player_t *player);
    int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player);
    int manage_key_released(sfKeyCode key_code, player_t *player);
    void move_player(game_t *game, player_t *player);
    clothes_t *create_start_clothes(game_t *game);
    int destroy_player(player_t *player);
    sfSprite **create_sprites(int nbr,
    const sfIntRect rect[nbr], sfTexture *texture);
    int destroy_all_sprites(sfSprite ***sprites);
    weapon_t *create_start_weapon(game_t *game);
    sfVector2f *create_corners(char **map);
    char **create_map(char *str);
    int is_parser(char c, char *to_compare);
    sfSprite *create_sprite(char **map);
    sfTexture *create_texture(char **map);
    level_t **create_levels(char *path, game_t *game);

    int is_parser(char c, char *to_compare);
    char **my_str_to_word_array(const char *src, char *pars);
    void my_free_word_array(char **array);
    int my_atoi(char *str_ptr);
    int my_putnbr(int nbr, char c);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strdup(const char *src);
    int my_strlen(const char *str);

    void display_enemies(game_t *game, enum levels level);
    void enemy_destroy(enemy_t *enemy);
    enemy_t **enemies_create(char *enemies_data, game_t *game);

#endif
