/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "level.h"
#include "prototype.h"

char **create_map(char *str)
{
    char **map = malloc(sizeof(char *) * 18);
    char **temp = my_str_to_word_array(str, "\n");

    if (!map || !temp)
        return NULL;
    for (int i = 0; i < 18; i++) {
        map[i] = malloc(sizeof(char) * 33);
        if (!map[i])
            return NULL;
        for (int j = 0; j < 32; j++)
            map[i][j] = temp[i][j];
        map[i][32] = '\0';
    }
    my_free_word_array(temp);
    return map;
}

void destroy_map(char **map)
{
    if (map) {
        for (int i = 0; i < 18; i++)
            free(map[i]);
        free(map);
    }
}

sfVector2f *create_map_corners(char **map)
{
    //en gros il faut capter ou sont les coins de chaque murs et les retourner dans un tableau de sfVector2f
    //pratique pour les collisions/raytracing
    return NULL;
}

void destroy_map_corners(sfVector2f *corners)
{
    if (corners)
        free(corners);
}
