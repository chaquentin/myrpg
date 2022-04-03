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
        sfSprite **all_sprite;
        sfRenderWindow *window;
        sfTexture *texture;
        sfClock *clock;
        enum game_scene scene;
        int framerate_limit;
        float delta_time;
    } game_t;

    typedef struct game_object_s {
        sfSprite *sprite;
        sfVector2f pos;
        enum all_sprites texture;
        void *data;
    } game_object_t;

    typedef struct weapon_s {
        enum all_sprites weapon;
        int ammo;
        int damage;
    } weapon_t;

    typedef struct player_s {
        game_object_t *weapon;
        sfSprite *sprite;
        sfSprite *clothes;
        sfVector2f pos;
        sfBool is_moving;
        enum all_sprites default_sprites;
        enum all_sprites actual_sprite;
        enum all_sprites clothes_sprite;
        int swag;
        int health;
        int speed;
        int *movement;
        int delta_time;
    } player_t;

#endif
