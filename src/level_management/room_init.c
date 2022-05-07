/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** room_init
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "enemies.h"
#include "level.h"
#include "structure.h"
#include "prototype.h"

level_t *create_level(enum levels level_name, char *str, game_t *game)
{
    level_t *level = malloc(sizeof(level_t));
    enemy_t **enemies = NULL;
    char **parts = my_str_to_word_array(str, "!");

    if (!level || !parts)
        return NULL;
    level->up = (sfVector2f) {-1, -1};
    level->down = (sfVector2f) {-1, -1};
    level->size.x = 32;
    level->size.y = 18;
    level->enemies = enemies_create(parts[1], game);
    level->map = create_map(parts[0], level->size);
    level->walls = create_map_walls(level, game);
    level->texture = create_map_texture(game, level->map, level);
    level->sprite = create_map_sprite(game, level->texture);
    level->level = level_name;
    my_free_word_array(parts);
    return level;
}

level_t **create_levels(char *path, game_t *game)
{
    level_t **levels = malloc(sizeof(level_t *) * (NBR_LEVELS + 1));
    char **parsed_levels = NULL;
    char *str = NULL;

    str = open_file(path);
    if (str == NULL || levels == NULL)
        return NULL;
    parsed_levels = my_str_to_word_array(str, "&");
    for (int i = 0; i < NBR_LEVELS; i++) {
        write(1, "creating level: ", 17);
        my_putnbr(i + 1, '\n');
        levels[i] = create_level((enum levels) i, parsed_levels[i + 1], game);
    }
    my_free_word_array(parsed_levels);
    free(str);
    levels[NBR_LEVELS] = NULL;
    return levels;
}

int destroy_levels(level_t **level)
{
    if (level == NULL)
        return (84);
    for (int i = 0; level[i]; i++) {
        write(1, "freeing level:  ", 16);
        my_putnbr(i + 1, '\n');
        destroy_map_walls(level[i]->walls);
        destroy_map(level[i]->map);
        destroy_enemies(level[i]->enemies);
        sfTexture_destroy(level[i]->texture);
        sfSprite_destroy(level[i]->sprite);
        free(level[i]);
    }
    free(level);
    return 0;
}
