/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** framebuffer
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "structure.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *pixels = malloc(sizeof(framebuffer_t));

    pixels->width = width;
    pixels->height = height;
    pixels->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    for (int i = 0; i < (width * height * 4); i++)
        pixels->pixels[i] = 0;
    return pixels;
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}
