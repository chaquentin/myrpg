/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** create_all_sprites
*/

#include "sprite_sheet.h"
#include <stdlib.h>

int destroy_sprite_array(sfSprite **sprites)
{
    if (!sprites)
        return 84;
    for (int i = 0; sprites[i]; i++)
        sfSprite_destroy(sprites[i]);
    free(sprites);
    return 0;
}

int destroy_all_sprites(sfSprite ***sprites)
{
    if (!sprites)
        return 84;
    for (int i = 0; sprites[i]; i++)
        destroy_sprite_array(sprites[i]);
    free(sprites);
    return 0;
}

sfSprite **create_sprites(int nbr, const sfIntRect rect[nbr],
sfTexture *texture)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * (nbr + 1));

    if (!sprites)
        return NULL;
    for (int i = 0; i < nbr; i++) {
        sprites[i] = NULL;
        sprites[i] = sfSprite_create();
        if (!sprites[i]) {
            destroy_sprite_array(sprites);
            return NULL;
        }
        sfSprite_setTexture(sprites[i], texture, sfTrue);
        sfSprite_setTextureRect(sprites[i], rect[i]);
    }
    sprites[nbr] = NULL;
    return sprites;
}
