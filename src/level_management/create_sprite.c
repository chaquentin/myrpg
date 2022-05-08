/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_sprite
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "level.h"
#include "prototype.h"

sfSprite *get_sprite_elevator(game_t *game, char c, sfVector2f pos,
level_t *level)
{
    if (c == 'E' && level->up.x == -1) {
        level->up = (sfVector2f) {pos.x * (64 * 0.9375),
        pos.y * (64 * 0.9375)};
        return (game->all_sprite[Decor][ElevatorDoor]);
    }
    if (c == 'e' && level->down.x == -1) {
        level->down = (sfVector2f) {pos.x * (64 * 0.9375),
        pos.y * (64 * 0.9375)};
        return (game->all_sprite[Decor][ElevatorDoor]);
    }
    return NULL;
}

sfSprite *get_sprite_wall(game_t *game, char **map, sfVector2i pos)
{
    int index = (map[pos.y][pos.x] == 'W') ? 0 : 16;

    if (pos.y > 0 && (map[pos.y - 1][pos.x] == 'W' ||
    map[pos.y - 1][pos.x] == 'w'))
        index += 1;
    if (pos.y < 17 && (map[pos.y + 1][pos.x] == 'W' ||
    map[pos.y + 1][pos.x] == 'w'))
        index += 2;
    if (pos.x < 31 && (map[pos.y][pos.x + 1] == 'W' ||
    map[pos.y][pos.x + 1] == 'w'))
        index += 4;
    if (pos.x > 0 && (map[pos.y][pos.x - 1] == 'W' ||
    map[pos.y][pos.x - 1] == 'w'))
        index += 8;
    return game->all_sprite[Wall][index];
}

sfSprite *get_sprite(game_t *game, char **map,
sfVector2f pos_f, level_t *level)
{
    sfVector2i pos = {(int)pos_f.x, (int)pos_f.y};

    if (map[pos.y][pos.x] == 'W' || map[pos.y][pos.x] == 'w')
        return get_sprite_wall(game, map, pos);
    if (map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'e')
        return get_sprite_elevator(game, map[pos.y][pos.x], pos_f, level);
    switch (map[pos.y][pos.x]) {
    case ' ':
        return game->all_sprite[Decor][WoodenFloor];
    }
    return game->all_sprite[Decor][ErrorSprite];
}

sfSprite *create_map_sprite(game_t *game, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {0, 0};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfTexture *create_map_texture(game_t *game, char **map, level_t *level)
{
    sfSprite *sprite = NULL;
    sfImage *image = NULL;
    sfTexture *texture = NULL;
    sfVector2f pos = {0, 0};

    sfRenderWindow_clear(game->window, sfBlack);
    for (int i = 0; i < 18 * 32; i++) {
        pos = (sfVector2f) {i % 32, i / 32};
        sprite = get_sprite(game, map, pos, level);
        if (sprite) {
            sfSprite_setScale(sprite, (sfVector2f) {0.9375, 0.9375});
            sfSprite_setPosition(sprite, (sfVector2f) {pos.x * (64 * 0.9375),
            pos.y * (64 * 0.9375)});
            sfRenderWindow_drawSprite(game->window, sprite, NULL);
        }
    }
    image = sfRenderWindow_capture(game->window);
    texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return texture;
}
