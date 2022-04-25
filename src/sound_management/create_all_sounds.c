/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_all_sounds
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

static const char *sounds_file[] = {"assets/sounds/chines.ogg",
"/assets/sounds/english.ogg", "/assets/sounds/german.ogg",
"/assets/sounds/spanish.ogg"};

static const char *musics_file[] = {};

static int my_arrlen(char **src)
{
    int i = 0;

    while (src[i])
        i++;
    return i;
}

sfMusic **create_all_musics(void)
{
    sfMusic **all_musics = NULL;

    all_musics = malloc(sizeof(sfMusic *) * my_arrlen(musics_file));
    if (!all_musics)
        return NULL;
    all_musics[my_arrlen(musics_file)] = NULL;
    for (int i = 0; all_musics[i]; i++) {
        all_musics[i] = sfMusic_createFromFile(sounds_file[i]);
        if (!all_musics[i]) {
            all_musics[i] = NULL;
            destroy_musics(all_musics);
            return NULL;
        }
    }
    return all_musics;
}

sfSoundBuffer **create_all_sounds_buffer(void)
{
    sfSoundBuffer **all_sounds = NULL;

    all_sounds = malloc(sizeof(sfSoundBuffer *) * my_arrlen(musics_file));
    if (!all_sounds)
        return NULL;
    all_sounds[my_arrlen(musics_file)] = NULL;
    for (int i = 0; all_sounds[i]; i++) {
        all_sounds[i] = sfSoundBuffer_createFromFile(sounds_file[i]);
        if (!all_sounds[i]) {
            all_sounds[i] = NULL;
            destroy_sounds_buffer(all_sounds);
            return NULL;
        }
    }
    return all_sounds;
}

sounds_t *create_all_sounds(void)
{
    sounds_t *sounds = NULL;

    sounds = malloc(sizeof(sounds_t));
    if (sounds == NULL)
        return (NULL);
    sounds->all_buffer = NULL;
    sounds->all_musics = NULL;
    sounds->all_musics = create_all_musics();
    sounds->all_buffer = create_all_sounds_buffer();
    if (!sounds->all_buffer || !sounds->all_musics) {
        destroy_sounds(sounds);
        return NULL;
    }
    return sounds;
}
