/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** put_pixel_framebuffer
*/

#include <SFML/Graphics.h>
#include "structure.h"

void put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    if ((x >= 0) && (x < framebuffer->width) &&
        (y >= 0) && (y < framebuffer->height)) {
    unsigned int rank = (x + (framebuffer->width * y)) * 4;
    framebuffer->pixels[rank + 0] = color.r;
    framebuffer->pixels[rank + 1] = color.g;
    framebuffer->pixels[rank + 2] = color.b;
    framebuffer->pixels[rank + 3] = color.a;
    }
    return;
}
