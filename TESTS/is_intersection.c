/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** is_intersection
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

sfVector2f is_intersection(sfVector2f p1, sfVector2f p2, sfVector2f p3, sfVector2f p4)
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
        return (sfVector2f){-1, -1};
    intersection.x = (b2 * c1 - b1 * c2) / delta;
    intersection.y = (a1 * c2 - a2 * c1) / delta;
    return (intersection);
}

int main(int argc, char **argv)
{
    sfVector2f p1 = {0, 0};
    sfVector2f p2 = {0, 0};
    sfVector2f p3 = {0, 0};
    sfVector2f p4 = {0, 0};
    sfVector2f intersection = {-1, -1};

    if (argc != 9)
        return 84;
    p1.x = atoi(argv[1]);
    p1.y = atoi(argv[2]);
    p2.x = atoi(argv[3]);
    p2.y = atoi(argv[4]);
    p3.x = atoi(argv[5]);
    p3.y = atoi(argv[6]);
    p4.x = atoi(argv[7]);
    p4.y = atoi(argv[8]);
    intersection = is_intersection(p1, p2, p3, p4);
    printf("%f %f\n", intersection.x, intersection.y);
    return (0);
}
