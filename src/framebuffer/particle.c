/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** particle
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "structure.h"
#include "prototype.h"

particle_control_t *particle_init(void)
{
    particle_control_t *particle_control = malloc(sizeof(particle_control_t));

    if (particle_control == NULL)
        return (NULL);
    particle_control->first = NULL;
    particle_control->last = NULL;
    return particle_control;
}

int particle_destroy(particle_control_t *control, particle_t *particle)
{
    particle_t *tmp = control->first;
    particle_t *prev = NULL;

    if (particle == NULL)
        return (1);
    while (tmp != NULL) {
        if (tmp->next == particle->next && prev == NULL) {
            control->first = particle->next;
            free(particle);
            return (0);
        }
        if (tmp->next == particle->next) {
            prev->next = particle->next;
            free(particle);
            return (0);
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return (1);
}

particle_t *particle_create(sfVector2f pos, sfColor color, float duration_max)
{
    particle_t *particle = malloc(sizeof(particle_t));

    if (!particle)
        return (NULL);
    particle->pos = pos;
    particle->color = color;
    particle->duration_max = duration_max;
    particle->duration = 0.0;
    particle->next = NULL;
    particle->prev = NULL;
    return (particle);
}

int particle_append(particle_control_t *particle_control, sfVector2f pos,
sfColor color, float duration_max)
{
    particle_t *particle = particle_control->first;
    particle_t *new = particle_create(pos, color, duration_max);

    if (!new)
        return 84;
    if (particle == NULL) {
        particle_control->first = new;
        particle_control->last = new;
        return 0;
    }
    while (particle->next != NULL)
        particle = particle->next;
    particle->next = new;
    particle_control->last = new;
    return 0;
}

int particle_update(game_t *game)
{
    particle_control_t *particle_control = game->particle;
    particle_t *particle = particle_control->first;
    particle_t *prev = NULL;
    particle_t *next = NULL;
    framebuffer_t *framebuffer = game->framebuffer;
    sfVector2f pos = {0, 0};

    decay_buffer(game->framebuffer, 1);
    if (particle == NULL)
        return 84;
    while (particle != NULL) {
        particle->duration += game->delta_time;
        for (int i = 0; i < 100 * game->delta_time; i++) {
            pos = iline(framebuffer, particle->pos, (int[3]) {get_randint(0,
            360), get_randint(0, 20), 0}, particle->color);
            dsquare(framebuffer, pos, get_randint(0, 5), particle->color);
        }
        if (particle->duration >= particle->duration_max) {
            next = particle->next;
            particle_destroy(particle_control, particle);
            particle = next;
            continue;
        }
        prev = particle;
        particle = prev->next;
    }
    return 0;
}
