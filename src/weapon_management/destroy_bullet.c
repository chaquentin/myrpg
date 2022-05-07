/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** destroy_bullet
*/

#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

int destroy_bullet(bullet_t *bullet)
{
    if (bullet == NULL)
        return 84;
    if (bullet->sound != NULL) {
        sfSound_stop(bullet->sound);
        sfSound_destroy(bullet->sound);
    }
    free(bullet);
    return 0;
}

all_bullet_t *remove_all_bullets(all_bullet_t *list)
{
    bullet_t *tmp = list->first;
    bullet_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        destroy_bullet(tmp);
        tmp = next;
    }
    return (0);
}
