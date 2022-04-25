/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** destroy_sounds
*/

#include <stdlib.h>
#include "structure.h"

int destroy_musics(sfMusic **musics)
{
    if (musics == NULL)
        return 84;
    for (int i = 0; musics[i]; i++) {
        sfMusic_destroy(musics[i]);
    }
    free(musics);
    return 0;
}

int destroy_sounds_buffer(sfSoundBuffer **soud_buffer)
{
    if (soud_buffer == NULL)
        return 84;
    for (int i = 0; soud_buffer[i]; i++) {
        sfMusic_destroy(soud_buffer[i]);
    }
    free(soud_buffer);
    return 0;
}

int destroy_sounds(sounds_t *sounds)
{
    if (sounds == NULL)
        return 84;
    destroy_musics(sounds->all_musics);
    destroy_sounds_buffer(sounds->all_buffer);
    free(sounds);
    return 0;
}
