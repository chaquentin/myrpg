/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** get_randint
*/

#include <stdlib.h>

int get_randint(int min, int max)
{
    if (min > max)
        return (-1);
    return (rand() % (max - min) + min);
}
