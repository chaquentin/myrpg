/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** sprite_sheet
*/

#ifndef SPRITE_SHEET_H_
    #define SPRITE_SHEET_H_

    #include "SFML/Graphics.h"

    #define PI 3.1415926535
    #define NBR_CAT 8
    #define NBR_DECOR 1
    #define NBR_WALL 21
    #define NBR_PLAYER 8
    #define NBR_SHIRT 8
    #define NBR_HAT 3
    #define NBR_PANTS 16
    #define NBR_ENEMIES 9
    #define NBR_WEAPON 3

    enum type{Decor, Wall, Player, Shirt, Hat, Pants, Weapon, Enemy};

    enum decor {WoodenFloor};
    static const sfIntRect decor_rect[1] = {{0, 0, 64, 64}};

    /*
    c'est possible de me refaire les murs comme si-dessous? merci quentin bebou
    en gros, si il y a la lettre c'est que il y a un trou dans cette direction, genre:
    ExtWallNSEW c'est ouvert partout
    ExtWall c'est ouvert nulle part
    */

    enum wall2 {ExtWall, ExtWallN, ExtWallS, ExtWallNS, ExtWallE, ExtWallNE,
    ExtWallSE, ExtWallNSE, ExtWallW, ExtWallNW, ExtWallSW, ExtWallNSW,
    ExtWallEW, ExtWallNEW, ExtWallSEW, ExtWallNSEW,
    IntWall, IntWallN, IntWallS, IntWallNS, IntWallE, IntWallNE,
    IntWallSE, IntWallNSE, IntWallW, IntWallNW, IntWallSW, IntWallNSW,
    IntWallEW, IntWallNEW, IntWallSEW, IntWallNSEW};

    enum wall {ExtWallNS, ExtWallNSE, ExtWallNSW, ExtWallEW, ExtWallNEW,
    ExtWallSEW, ExtWallNE, ExtWallNW, ExtWallSE, ExtWallSW,
    IntWallNS, IntWallNSE, IntWallNSW, IntWallEW, IntWallNEW,
    IntWallSEW, IntWallNE, IntWallNW, IntWallSE, IntWallSW, IntWallSquare};

    static const sfIntRect wall_rect[21] = {{64, 0, 64, 64}, {64, 64, 64, 64},
    {64, 128, 64, 64}, {64, 192, 64, 64}, {64, 256, 64, 64}, {64, 320, 64, 64},
    {64, 384, 64, 64}, {64, 448, 64, 64}, {64, 512, 64, 64}, {64, 576, 64, 64},
    {128, 0, 64, 64}, {128, 64, 64, 64}, {128, 128, 64, 64},
    {128, 192, 64, 64}, {128, 256, 64, 64}, {128, 320, 64, 64},
    {128, 384, 64, 64}, {128, 448, 64, 64}, {128, 512, 64, 64},
    {128, 576, 64, 64}, {128, 640, 64, 64}};

    enum player {PlayerGun1, PlayerGun2, PlayerGun3, PlayerGun4,
    PlayerRifle1, PlayerRifle2, PlayerRifle3, PlayerRifle4};
    static const sfIntRect player_rect[8] = {{192, 0, 64, 64}, {256, 0, 64, 64},
    {320, 0, 64, 64}, {384, 0, 64, 64}, {192, 64, 64, 64},
    {256, 64, 64, 64}, {320, 64, 64, 64}, {384, 64, 64, 64}};

    enum shirt {TankRifle, TankGun, BlackRifle, BlackGun,
    FlowerRifle, FlowerGun, FireRifle, FireGun};
    static const sfIntRect shirt_rect[8] = {{640, 0, 64, 64}, {704, 0, 64, 64},
    {640, 64, 64, 64}, {704, 64, 64, 64}, {640, 128, 64, 64},
    {740, 128, 64, 64}, {640, 192, 64, 64}, {704, 192, 64, 64}};
    static int shirt_swag[4] = {1, 5, 15, 25};

    enum hat {BlackCap, BlackDourag, FireCap};
    static const sfIntRect hat_rect[3] = {{768, 0, 64, 64}, {768, 64, 64, 64},
    {768, 128, 64, 64}};
    static int hat_swag[3] = {3, 15, 20};

    enum pants {BlueGun1, BlueGun2, BlueGun3, BlueGun4,
    BlueRifle1, BlueRifle2, BlueRifle3, BlueRifle4,
    BlackGun1, BlackGun2, BlackGun3, BlackGun4,
    BlackRifle1, BlackRifle2, BlackRifle3, BlackRifle4};
    static const sfIntRect pants_rect[16] = {{832, 0, 64, 64}, {896, 0, 64, 64},
    {960, 0, 64, 64}, {1024, 0, 64, 64}, {1088, 0, 64, 64}, {1152, 0, 64, 64},
    {1216, 0, 64, 64}, {1280, 0, 64, 64}, {832, 64, 64, 64}, {896, 64, 64, 64},
    {960, 64, 64, 64}, {1024, 64, 64, 64}, {1088, 64, 64, 64},
    {1152, 64, 64, 64}, {1216, 64, 64, 64}, {1280, 64, 64, 64}};
    static int pants_swag[2] = {1, 2};

    enum enemies {EnemyGun1, EnemyGun2, EnemyGun3,
    EnemyGlock1, EnemyGlock2, EnemyGlock3,
    EnemyShotgun1, EnemyShotgun2, EnemyShotgun3};
    static const sfIntRect enemies_rect[9] = {{448, 0, 64, 64}, {512, 0, 64, 64},
    {576, 0, 64, 64}, {448, 64, 64, 64}, {512, 64, 64, 64},
    {576, 64, 64, 64}, {448, 256, 64, 64}, {512, 256, 64, 64},
    {576, 256, 64, 64}};

    enum weapon {Gun, M4, Sniper};
    static const sfIntRect weapon_rect[3] = {{192, 128, 64, 64}, {256, 128, 64, 64},
    {256, 192, 64, 64}};
    static const int gun_damage[3][4] = {{9, 24, 2.3, 1.3},
    {30, 33, 0.1, 3.1}, {10, 88, 1.25, 3.37}};

    static const int swag[] = {15, 25, 5, 1, 3, 15, 20};

#endif
