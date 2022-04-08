/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** structure
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "sprite_sheet.h"
    #include "enemies.h"
    #include "level.h"

    typedef struct enemy_jump_s {
        sfBool is_jumping;
        int since;
        sfVector2f pos1;
        sfVector2f pos2;
    } enemy_jump_t;

    typedef struct enemy_s {
        enemy_jump_t *jump;
        sfVector2f player_pos;
        sfVector2f idle_around;
        sfVector2f pos;
        sfTexture *texture;
        sfSprite *sprite;
        sfBool alive;
        enum behaviours behaviour;
        enum enemies type;
        int angle; 
        int speed;
        int jump_rate;
        int idled_since;
    } enemy_t;

    typedef struct level_s {
        enemy_t **enemies;
        sfVector2f *corners;
        sfSprite *sprite;
        sfTexture *texture;
        enum levels level;
        char **map;
    } level_t;

    typedef struct game_s {
        sfSprite ***all_sprite;
        level_t **levels;
        sfRenderWindow *window;
        sfTexture *texture;
        sfClock *clock;
        enum levels current_level;
        enum game_scene scene;
        int framerate_limit;
        float delta_time;
    } game_t;

    typedef struct weapon_s {
        sfSprite *sprite;
        sfBool is_gun;
        enum weapon weapon;
        int ammo;
        int damage;
        float reload_time;
        float fire_rate;
    } weapon_t;

    typedef struct clothes_s {
        sfSprite *shirt_sprite;
        sfSprite *hat_sprite;
        sfSprite *pants_sprite;
        enum hat hat;
        enum shirt top;
        enum pants pants;
        sfBool is_gun;
        int swag;
    } clothes_t;

    typedef struct player_s {
        weapon_t *weapon;
        clothes_t *clothes;
        sfSprite *sprite;
        sfVector2f pos;
        enum player player;
        int swag;
        int health;
        int speed;
        int *movement;
        int delta_time;
    } player_t;

#endif
