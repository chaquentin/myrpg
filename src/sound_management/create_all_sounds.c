/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_all_sounds
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

static const char *sounds_file[] = {"asset/sounds/chinese.ogg",
"asset/sounds/english.ogg", "asset/sounds/german.ogg",
"asset/sounds/spanish.ogg"};

static const char *musics_file[] = {};

static int my_arrlen(void **src)
{
    int i = 0;

    while (src[i])
        i++;
    return i;
}

sfMusic **create_all_musics(void)
{
    sfMusic **all_musics = NULL;
    int length = my_arrlen((void **) musics_file);

    all_musics = malloc(sizeof(sfMusic *) * (length + 1));
    if (!all_musics)
        return NULL;
    all_musics[length] = NULL;
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
    int length = my_arrlen((void **) sounds_file);

    all_sounds = malloc(sizeof(sfSoundBuffer *) * (length + 1));
    if (!all_sounds)
        return NULL;
    all_sounds[length] = NULL;
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
