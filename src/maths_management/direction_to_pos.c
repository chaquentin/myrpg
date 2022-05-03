/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** direction_to_pos
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <math.h>
#include "structure.h"
#include "prototype.h"

sfVector2f direction_to_pos(sfVector2f pos, float angle)
{
    sfVector2f new_pos = {-1, -1};

    new_pos.x = cos(angle * M_PI / 180) * 2000;
    new_pos.y = sin(angle * M_PI / 180) * 2000;
    return (new_pos);
}