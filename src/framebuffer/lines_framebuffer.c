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

void dline(framebuffer_t *buf, sfVector2f pos[2], int w, sfColor c)
{
    sfVector2f out = {pos[0].x, pos[0].y};
    int dx = abs((int) (pos[1].x - pos[0].x));
    int dy = abs((int) (pos[1].y - pos[0].y));
    int err = dx + dy, e2;
    int sx = -1;
    int sy = -1;

    if (pos[0].x < pos[1].x)
        sx = 1;
    if (pos[0].y < pos[1].y)
        sy = 1;
    while (1) {
        dsquare(buf, out, w, c);
        if (out.x == pos[1].x && out.y == pos[1].y)
            break;
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            out.x += sx;
        }
        if (e2 <= dx) {
            err += dx;
            out.y += sy;
        }
    }
    return;
}

sfVector2f iline(framebuffer_t *buf, sfVector2f p1, int arg[3], sfColor c)
{
    sfVector2f p2;
    double rad = (arg[0] / 180.0) * 3.141592554;
    double cosinus = cos(rad);
    double sinus = sin(rad);

    p2.x = p1.x + (arg[1] * cosinus);
    p2.y = p1.y + (arg[1] * sinus);
    dline(buf, (sfVector2f[2]) {p1, p2}, arg[2], c);
    return p2;
}

void dcircle(framebuffer_t *buf, sfVector2f pos, sfColor col, int r[2])
{
    double angle = 0.00;

    for (int i = 0; i < 360; i++, angle += 1) {
        iline(buf, pos, (int[3]) {angle, r[0], r[1]}, col);
    }
    return;
}
