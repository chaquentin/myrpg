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

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    enum enemy_sounds {
    Idle_1, Idle_2, Idle_3, 
    Spotted_1, Spotted_2, Spotted_3, 
    Jump_1, Jump_2, Jump_3};

    enum weapons {Knife, Baseball, Gun, Toothbrush};
    enum behaviours {Idle, Searching, Attacking};
    enum game_scene {Menu, Game, Option, Pause, Quit, Win};

    typedef struct enemy_jump_s {
        sfBool is_jumping;
        int since;                   //jump since n milliseconds
        sfVector2f pos1;             //from xy
        sfVector2f pos2;             //to xyp
    } enemy_jump_t;

    typedef struct enemy_s {           //enemy pos
        sfVector2f player_pos;       //last seen player pos, {-1, -1} if never seen the player.
        sfVector2f idle_around;      //pos that the enemy need to be around when idle
        int angle;                   //0 is at the right, 180 at the left 
        int speed;                   //can jump every n/100 seconds
        sfBool alive;                //explicit enough dumbass
        int idled_for;               //time since last action
        enemy_jump_t *jump;          //contains jumping data (see above)
        enum weapons weapon;         //which weapon to use
        enum behaviours behaviour;   //what's the enemy's behaviour
    } enemy_t;

#endif
