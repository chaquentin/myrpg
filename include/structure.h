/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** structure
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

    #include <SFML/Graphics.h>
    #include "sprite_sheet.h"
    #include "enemies.h"

    typedef struct game_s {
        sfSprite **all_sprite;
        sfRenderWindow *window;
        sfTexture *texture;
        enum game_scene scene;
        int framerate_limit;
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
        sfVector2f pos;
        sfBool is_moving;
        enum all_sprites my_sprite;
        int swag;
        int health;
        int speed;
    } player_t;

#endif /* !STRUCTURE_H_ */
