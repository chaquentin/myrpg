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
    int game(game_t *game, player_t *player, sfEvent event);
    int manage_scene(game_t *game);

    void destroy_game(game_t *game);

//===================================BUTTON===================================//

    button_t* create_button(enum button type, game_t *game,
    enum game_scene next_scene);


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

    char **create_map(char *str, sfVector2i map_size);
    sfSprite *create_map_sprite(game_t *game, sfTexture *texture);
    sfTexture *create_map_texture(game_t *game, char **map, level_t *level);
    level_t **create_levels(char *path, game_t *game);
    void display_map_sprite(game_t *game);

    line_t *create_map_walls(level_t *level, game_t *game);
    int count_walls(level_t *level);
    int count_adjacent_walls(level_t *level, sfVector2i pos);

    void destroy_levels(level_t **level);
    void destroy_map(char **map);
    void destroy_map_walls(line_t *walls);

//=================================ENEMIES==================================//

    enemy_t **enemies_create(char *enemies_data, game_t *game);
    void display_enemies(game_t *game);
    int enemy_actions(game_t *game, player_t *player);
    int enemy_turn(game_t *game, enemy_t *enemy);

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

//=============================DRAWING=FUNCTIONS=============================//

    void draw_line(game_t *game, sfVector2f p1, sfVector2f p2, sfColor color, int thick);
    void draw_point(sfRenderWindow *window, sfVector2f point, sfColor color, int size);
    void draw_rays(player_t *player, game_t *game, line_t *walls);

//===================================MATH====================================//

    sfVector2f is_intersection(sfVector2f p1, sfVector2f p2, sfVector2f p3, sfVector2f p4);
    float get_distance(sfVector2f p1, sfVector2f p2);
    int get_randint(int min, int max);

#endif
