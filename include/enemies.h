/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** enemies
*/

/*
THIS IS A TEMPORARY FILE JUST TO GIVE AN IDEA OF HOW THE ENEMIES WILL WORK
*/
#ifndef ENEMIES_H
    #define ENEMIES_H

    enum enemy_sounds {
    Idle_1, Idle_2, Idle_3, 
    Spotted_1, Spotted_2, Spotted_3, 
    Jump_1, Jump_2, Jump_3};
    enum behaviours {Idle, Searching, Attacking};
    enum game_scene {Menu, Game, Option, Pause, Quit, Win};
    enum enemy_type {Error, Purple, Hood};

#endif
