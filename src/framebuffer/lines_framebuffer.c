/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** lines_framebuffer
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

void dsquare(framebuffer_t *buf, sfVector2f pos, int size, sfColor col)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            put_pixel(buf, pos.x + j, pos.y + i, col);
    return;
}

sfVector2f iline(framebuffer_t *buf, sfVector2f p1, int arg[3], sfColor c)
{
    sfVector2f p2;
    double rad = (arg[0] / 180.0) * M_PI;
    double cosinus = cos(rad);
    double sinus = sin(rad);

    p2.x = p1.x + (arg[1] * cosinus);
    p2.y = p1.y + (arg[1] * sinus);
    return p2;
}
