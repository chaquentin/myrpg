/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** all_bullet_creation
*/

#include <stdlib.h>
#include "structure.h"

int display_bullets(all_bullet_t *list, game_t *game)
{
    bullet_t *tmp = list->first;

    while (tmp != NULL) {
        sfSprite_setRotation(tmp->sprite, tmp->angle);
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    return 0;
}

bullet_t *create_bullet(game_t *game, sfVector2f pos, int damage, float angle)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    static int id = 0;

    if (bullet == NULL)
        return (NULL);
    bullet->sound = sfSound_create();
    sfSound_setBuffer(bullet->sound, game->sounds->all_buffer[6]);
    sfSound_setVolume(bullet->sound, game->sounds->sound_vol);
    sfSound_play(bullet->sound);
    bullet->sprite = game->all_sprite[Weapon][Bullet];
    sfSprite_setOrigin(bullet->sprite, (sfVector2f){30, 30});
    bullet->pos = pos;
    bullet->id = id;
    bullet->angle = angle;
    bullet->damage = damage;
    bullet->next = NULL;
    id = (id > 1000) ? 0 : id + 1;
    return (bullet);
}

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
