/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** get_distance
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

float get_distance(sfVector2f p1, sfVector2f p2)
{
    float x = (sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
    return x;
}
