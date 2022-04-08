/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** room_init
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "enemies.h"
#include "level.h"
#include "structure.h"
#include "prototype.h"

char *open_file(char *path)
{
    struct stat stats;
    char *buf = NULL;
    int fd = 0;

    write(1, "opening levels file: ", 22);
    if (stat(path, &stats) == -1) {
        write(1, "FAILED\n", 6);
        return NULL;    
    }
    fd = open(path, O_RDONLY);
    buf = malloc(stats.st_size + 1);
    if (fd == -1 || read(fd, buf, stats.st_size) == -1 || buf == NULL) {
        write(1, "FAILED\n", 6);
        return NULL;
    }
    buf[stats.st_size] = '\0';
    close(fd);
    write(1, "SUCCESS\n", 8);
    return buf;
}

level_t *create_level(enum levels level_name, char *str, game_t *game)
{
    level_t *level = malloc(sizeof(level_t));
    enemy_t **enemies = NULL;
    char **parts = my_str_to_word_array(str, "!");

    if (!level || !parts)
        return NULL;
    level->enemies = enemies_create(parts[1], game);
    level->map = create_map(parts[0]);
    level->corners = create_corners(level->map);
    level->texture = create_texture(level->map);
    level->sprite = create_sprite(level->map);
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


void free_levels(level_t **level)
{
    for (int i = 0; level[i]; i++) {
        free(level[i]->corners);
        /*
        for (int j = 0; level[i]->map[j]; j++)
            free(level[i]->map[j]);
        free(level[i]->map);
        sfTexture_destroy(level[i]->texture);
        sfSprite_destroy(level[i]->sprite);
        */
        write(1, "freeing level:  ", 16);
        my_putnbr(i + 1, '\n');
        for (int j = 0; level[i]->enemies[j]; j++)
            enemy_destroy(level[i]->enemies[j]);
        free(level[i]->enemies);
        free(level[i]);
    }
    free(level);
}
