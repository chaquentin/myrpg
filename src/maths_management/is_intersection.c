/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** is_intersection
*/

#include <SFML/Graphics.h>

sfVector2f is_intersection(sfVector2f p1, sfVector2f p2, sfVector2f p3,
sfVector2f p4)
{
    sfVector2f intersection = {-1, -1};
    float a1 = p2.y - p1.y;
    float b1 = p1.x - p2.x;
    float c1 = a1 * p1.x + b1 * p1.y;
    float a2 = p4.y - p3.y;
    float b2 = p3.x - p4.x;
    float c2 = a2 * p3.x + b2 * p3.y;
    float delta = a1 * b2 - a2 * b1;

    if (delta == 0)
        return (sfVector2f) {-1, -1};
    intersection.x = (b2 * c1 - b1 * c2) / delta;
    intersection.y = (a1 * c2 - a2 * c1) / delta;
    return (intersection);
}
