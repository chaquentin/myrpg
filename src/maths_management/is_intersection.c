/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** is_intersection
*/

#include <SFML/Graphics.h>
#include <stdio.h>

float get_biggest(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

float get_smallest(float a, float b)
{
    if (a < b)
        return a;
    return b;
}

sfVector2f is_intersection(sfVector2f A, sfVector2f B,
sfVector2f C, sfVector2f D)
{
    sfVector2f inter = {-1, -1};
    float a1 = B.y - A.y;
    float b1 = A.x - B.x;
    float c1 = a1 * A.x + b1 * A.y;
    float a2 = D.y - C.y;
    float b2 = C.x - D.x;
    float c2 = a2 * C.x + b2 * C.y;
    float delta = a1 * b2 - a2 * b1;

    if (delta == 0)
        return (sfVector2f) {-1, -1};
    inter.x = (b2 * c1 - b1 * c2) / delta;
    inter.y = (a1 * c2 - a2 * c1) / delta;
    if (inter.x < get_smallest(A.x, B.x) || inter.x > get_biggest(A.x, B.x)
    || (inter.x < get_smallest(C.x, D.x) || inter.x > get_biggest(C.x, D.x))
    || (inter.y < get_smallest(A.y, B.y) || inter.y > get_biggest(A.y, B.y))
    || (inter.y < get_smallest(C.y, D.y) || inter.y > get_biggest(C.y, D.y)))
        return (sfVector2f) {-1, -1};
    return (inter);
}
