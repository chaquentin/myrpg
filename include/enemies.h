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

    enum enemy_types {Gangster, Hoods, Durag};
    static int shooting_distance[3] = {100, 200, 500};
    static int shooting_speed[3] = {1, 2, 3};

    #define NBR_ACTIONS 3
    #define MIN_TIME_IDLE 500
    #define MAX_TIME_IDLE 1000
    #define VIEW_DISTANCE 250
    #define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

#endif
