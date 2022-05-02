/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** add_and_rm_bullet
*/

#include <stdlib.h>
#include "prototype.h"
#include "structure.h"

int remove_id(all_bullet_t *list, int id)
{
    bullet_t *tmp = list->first;
    bullet_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->id == id && prev == NULL) {
            list->first = tmp->next;
            free(tmp);
            list->size--;
            return (0);
        } else if (tmp->id == id) {
            prev->next = tmp->next;
            free(tmp);
            list->size--;
            return (0);
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 84;
}

int remove_last(all_bullet_t *list)
{
    bullet_t *tmp = list->first;
    bullet_t *prev = NULL;

    if (list->size == 0)
        return (0);
    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == NULL)
        list->first = NULL;
    else
        prev->next = NULL;
    list->last = prev;
    list->size--;
    destroy_bullet(tmp);
    return (0);
}

int remove_first(all_bullet_t *list)
{
    bullet_t *tmp = list->first;

    list->first = list->first->next;
    destroy_bullet(tmp);
    list->size--;
    return (0);
}

int add_first(all_bullet_t *list, game_t *game, sfVector2f pos, int damage)
{
    bullet_t *new = create_bullet(game, pos, damage);

    if (new == NULL)
        return (84);
    if (list->first == NULL) {
        list->first = new;
        list->last = new;
    } else {
        new->next = list->first;
        list->first = new;
    }
    list->size++;
    return (0);
}

int append(all_bullet_t *list, game_t *game, sfVector2f pos, int damage)
{
    bullet_t *new = create_bullet(game, pos, damage);

    if (new == NULL)
        return (84);
    if (list->first == NULL) {
        list->first = new;
        list->last = new;
    } else {
        list->last->next = new;
        list->last = new;
    }
    list->size++;
    return (0);
}
