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

    typedef struct game_s {
        sfSprite ***all_sprite;
        sfRenderWindow *window;
        sfTexture *texture;
        sfClock *clock;
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
        enum nigger player;
        int swag;
        int health;
        int speed;
        int *movement;
        int delta_time;
    } player_t;

#endif
