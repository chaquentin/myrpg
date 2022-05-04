/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** get_angle
*/

#include <SFML/Graphics.h>
#include <math.h>

float get_angle(sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f vector = {pos2.x - pos1.x, pos2.y - pos1.y};
    float angle = atan(vector.x / vector.y) * (180.0 / M_PI) * -1;

    if (vector.y > 0)
        angle += 180;
    return (angle);
}
