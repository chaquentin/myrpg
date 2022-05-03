/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** play_music
*/

#include <stdlib.h>
#include "structure.h"

void play_music(sfMusic *music)
{
    if (sfMusic_getStatus(music) != sfPlaying) {
        sfMusic_play(music);
        sfMusic_setLoop(music, sfTrue);
    }
}

int stop_music(sfMusic *music)
{
    sfMusic_stop(music);
    return 0;
}

int pause_music(sfMusic *music)
{
    sfMusic_pause(music);
    return 0;
}