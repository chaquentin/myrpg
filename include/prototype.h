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
    int menu(game_t *game, player_t *player, sfEvent event);
    int option(game_t *game, player_t *player, sfEvent event);
    int help(game_t *game, player_t *player, sfEvent event);
    int scene_button_management(game_t *game, sfEvent *event,
    button_t **scene_button);
    int update_clock(game_t *game);

    void destroy_game(game_t *game);

//===================================BUTTON===================================//

    button_t *create_button(enum button type, game_t *game,
    enum game_scene next_scene);
    int display_button(button_t **button, game_t *game);
    int destroy_button(button_t **button);

//==================================PLAYER===================================//

    player_t *create_player(game_t *game);
    int display_player(game_t *game, player_t *player);
    void move_player(game_t *game, player_t *player);
    void fill_mouse(game_t *game, player_t *player);
    int display_health(game_t *game, player_t *player, int is_destruct);
    int display_guns(game_t *game, player_t *player, int is_destruct);
    int shoot(game_t *game, player_t *player, int is_click);
    int update_sprite(player_t *player, game_t *game);
    int change_weapon(player_t *player, game_t *game, enum weapon type);
    int manage_player_colision(game_t *game, player_t *player,
    sfVector2i movement);
    int display_player_stats(game_t *game, player_t *player);

    int destroy_player(game_t *game, player_t *player);
    int destroy_weapon(weapon_t *weapon);

//================================ACCESSORIES================================//

    clothes_t *create_start_clothes(game_t *game);
    weapon_t *create_start_weapon(game_t *game);

//==================================SPRITES==================================//

    sfSprite **create_all_sprite(int nbr,
    const sfIntRect rect[nbr], sfTexture *texture);
    sprite_t *create_sprite(char *path);

    int destroy_sprite(sprite_t *sprite);
    int destroy_all_sprites(sfSprite ***sprites);

//====================================MAP====================================//

    char **create_map(char *str, sfVector2i map_size);
    sfSprite *create_map_sprite(game_t *game, sfTexture *texture);
    sfTexture *create_map_texture(game_t *game, char **map, level_t *level);
    level_t **create_levels(char *path, game_t *game);
    void display_map_sprite(game_t *game);
    char *open_file(char *path);

    line_t *create_map_walls(level_t *level, game_t *game);
    int count_walls(level_t *level);
    int count_adjacent_walls(level_t *level, sfVector2i pos);

    int destroy_levels(level_t **level);
    void destroy_map(char **map);
    void destroy_map_walls(line_t *walls);

//=================================ENEMIES==================================//

    enemy_t **enemies_create(char *, game_t *);
    void display_enemies(game_t *);
    int enemy_actions(game_t *, player_t *);
    int enemy_turn(game_t *, enemy_t *);

    int enemy_idle(game_t *, player_t *, int);
    int enemy_search(game_t *, player_t *, int);
    int enemy_attack(game_t *, player_t *, int);

    int enemy_debug(game_t *, player_t *);

    void destroy_enemies(enemy_t **);

//==================================EVENTS===================================//

    int manage_key_pressed(game_t *game, sfKeyCode key_code, player_t *player);
    int manage_key_released(sfKeyCode key_code, player_t *player);
    void get_event(game_t *game, sfEvent *event, button_t **all_button);
    int manage_mouse(game_t *game, sfEvent *event, button_t **all_button);
    int manage_released(game_t *game, button_t **all_button);

//===================================WORDS===================================//

    int is_parser(char c, char *to_compare);
    char **my_str_to_word_array(const char *src, char *pars);
    int my_atoi(char *str_ptr);
    int my_putnbr(int nbr, char c);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strdup(const char *src);
    int my_strlen(const char *str);
    char *tranform_in_str(int nbr);
    char *get_file(const char *path);
    int my_arrlen(const char *src[]);

    void my_free_word_array(char **array);

//===================================VIEW====================================//

    sfView *create_view(game_t *game, int debug);
    void view_update(game_t *game, player_t *player);

    void destroy_view(game_t *game);

//===================================MATH====================================//

    sfVector2f is_intersection(sfVector2f, sfVector2f, sfVector2f, sfVector2f);
    float get_distance(sfVector2f, sfVector2f);
    int get_randint(int, int);
    float get_angle(sfVector2f, sfVector2f);

//==================================SOUNDS===================================//

    sounds_t *create_all_sounds(void);
    int destroy_sounds(sounds_t *sounds);
    int destroy_sounds_buffer(sfSoundBuffer **soud_buffer);
    int destroy_musics(sfMusic **musics);
    void play_music(sfMusic *music);
    int destroy_music(sfMusic *music);
    int stop_music(sfMusic *music);

//=================================BULLETS===================================//

    all_bullet_t *init_list(void);
    bullet_t *create_bullet(game_t *game, sfVector2f pos, int damage, float);
    int add_first(all_bullet_t *list, bullet_t *bullet);
    int append(all_bullet_t *list, bullet_t *bullet);
    int fire_weapon(game_t *game, player_t *player);
    int fire_weapon_enemy(game_t *game, enemy_t *enemy);
    int display_bullets(all_bullet_t *list, game_t *game);
    int update_bullets(game_t *game);
    int manage_bullet(game_t *game, player_t *player);

    int remove_first(all_bullet_t *list);
    int remove_last(all_bullet_t *list);
    int remove_id(all_bullet_t *list, int id);
    int destroy_all_bullet(all_bullet_t *list);
    int destroy_bullet(bullet_t *bullet);

//===================================HELP====================================//

    button_t **create_help_button(game_t *game);
    button_t **create_languages_button(game_t *game);
    sfSound *create_help_sound(game_t *game);
    int init_help_sprite(sfSprite *sprite, sfSprite *box);
    int destroy_help(sprite_t *background, button_t **scene_button,
    button_t **languages_button, sfSound *sound);

//==================================OPTIONS==================================//

    text_option_t *create_option(game_t *game);
    int update_text(text_option_t *option_txt, game_t *game);
    int display_option(game_t *game, button_t **scene_button,
    button_t **option_button, text_option_t *option_txt);
    int get_option_event(game_t *game, sfEvent *event,
    button_t **scene_button, button_t **option_button);

//==============================NPC=MANAGEMENT===============================//

    npc_t **create_all_npc(game_t *game);
    int display_all_npc(game_t *game);
    int npc_event(game_t *game, player_t *player);
    int luca_action(game_t *game, player_t *player);
    int matthias_action(game_t *game, player_t *player);
    int write_dialogue(game_t *game, char *dialogue);

    int destroy_all_npc(npc_t **npc);

//================================FRAMEBUFFER================================//

    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void framebuffer_destroy(framebuffer_t *framebuffer);
    void draw_framebuffer(game_t *game);
    framebuffer_t *fill_buffer(framebuffer_t *framebuffer, sfColor color);
    int decay_buffer(framebuffer_t *framebuffer, int a);
    void put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
    void dsquare(framebuffer_t *buf, sfVector2f pos, int size, sfColor col);
    void dline(framebuffer_t *buf, sfVector2f pos[2], int w, sfColor c);
    sfVector2f iline(framebuffer_t *buf, sfVector2f p1, int arg[3], sfColor c);
    void dcircle(framebuffer_t *buf, sfVector2f pos, sfColor col, int r[2]);

    int particle_append(particle_control_t *particle, sfVector2f pos, sfColor color, float duration_max);
    int particle_update(game_t *game);
    int particle(game_t *game, enum particle_type type, sfVector2f pos);
    particle_control_t *particle_init(void);

#endif
