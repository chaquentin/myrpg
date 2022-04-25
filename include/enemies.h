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
    enum game_scene {Quit, Menu, Game, Option, Pause, Win, Help};

    #define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

#endif
