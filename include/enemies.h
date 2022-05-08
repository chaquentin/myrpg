/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** enemies
*/

#ifndef ENEMIES_H
    #define ENEMIES_H

    enum enemy_sounds {
    Idle_1, Idle_2, Idle_3,
    Spotted_1, Spotted_2, Spotted_3,
    Jump_1, Jump_2, Jump_3};
    enum behaviours {Idle, Searching, Attacking};
    enum actions {Sound, Jump, Turn};

    enum game_scene {Quit, Menu, Game, Option, Pause, Win, Help};

    enum particle_type {Blood, Steps};

    enum enemy_types {Gangster, Hoods, Durag, OusmaneSeisme};
    static int shooting_dist[4] = {200, 300, 499, 750};
    static int shooting_speed[4] = {10, 20, 30, 3};
    static int shooting_damage[4] = {5, 10, 25, 25};
    static int life_enemy[4] = {100, 100, 100, 1000};

    #define NBR_ACTIONS 3
    #define MIN_TIME_IDLE 250
    #define MAX_TIME_IDLE 500
    #define VIEW_DISTANCE 500
    #define ENEMY_SPEED 50

#endif
