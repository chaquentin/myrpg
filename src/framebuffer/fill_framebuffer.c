/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** fill_framebuffer
*/

#include <SFML/Graphics.h>
#include "structure.h"

framebuffer_t *fill_buffer(framebuffer_t *framebuffer, sfColor color)
{
    int w = framebuffer->width;
    int h = framebuffer->height;

    for (int i = 0; i < w * h * 4; i++)
        framebuffer->pixels[i] = color.r;
    return framebuffer;
}
