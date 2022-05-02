/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** all_bullet_creation
*/

#include <stdlib.h>
#include "structure.h"

bullet_t *create_bullet(game_t *game, sfVector2f pos, int damage)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    static int id = 0;

    if (bullet == NULL)
        return (NULL);
    bullet->sprite = game->all_sprite[Weapon][Bullet];
    bullet->pos = pos;
    bullet->id = id;
    bullet->damage = damage;
    bullet->next = NULL;
    id = (id > 1000) ? 0 : id + 1;
    return (bullet);
}

int destroy_bullet(bullet_t *bullet)
{
    if (bullet == NULL)
        return 84;
    free(bullet);
    return 0;
}

all_bullet_t *init_list(void)
{
    all_bullet_t *list = NULL;

    list = malloc(sizeof(all_bullet_t));
    if (list == NULL)
        return (NULL);
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return (list);
}

int destroy_all_bullet(all_bullet_t *list)
{
    bullet_t *tmp = list->first;
    bullet_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        destroy_bullet(tmp);
        tmp = next;
    }
    free(list);
    return (0);
}
