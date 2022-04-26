/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** sprite_management
*/

#include <stdlib.h>
#include "structure.h"

int destroy_sprite(sprite_t *sprite)
{
    if (!sprite)
        return 84;
    if (sprite->sprite)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture)
        sfTexture_destroy(sprite->texture);
    free(sprite);
    return 0;
}

sprite_t *create_sprite(char *path)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (!sprite)
        return NULL;
    sprite->texture = sfTexture_createFromFile(path, NULL);
    if (!sprite->texture) {
        destroy_sprite(sprite);
        return NULL;
    }
    sprite->sprite = sfSprite_create();
    if (!sprite->sprite) {
        destroy_sprite(sprite);
        return NULL;
    }
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->pos = (sfVector2f) {0, 0};
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return sprite;
}
