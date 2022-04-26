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
    #define NBR_CAT 9
    #define NBR_DECOR 3
    #define NBR_WALL 32
    #define NBR_PLAYER 8
    #define NBR_SHIRT 8
    #define NBR_HAT 3
    #define NBR_PANTS 16
    #define NBR_ENEMIES 9
    #define NBR_WEAPON 3
    #define NBR_BUTTON 21
    #define SPRITESHEET_PATH "asset/sprite_sheet.png"

    enum type{Decor, Wall, Player, Shirt, Hat, Pants, Weapon, Enemy, Button};

    enum decor {WoodenFloor, ErrorSprite, OptionGround};
    static const sfIntRect decor_rect[NBR_DECOR] = {{0, 0, 64, 64}, {0, 1216, 64, 64},
    {1334, 256, 512, 512}};

    enum wall {ExtWall, ExtWallN, ExtWallS, ExtWallNS, ExtWallE, ExtWallNE,
    ExtWallSE, ExtWallNSE, ExtWallW, ExtWallNW, ExtWallSW, ExtWallNSW,
    ExtWallEW, ExtWallNEW, ExtWallSEW, ExtWallNSEW,
    IntWall, IntWallN, IntWallS, IntWallNS, IntWallE, IntWallNE,
    IntWallSE, IntWallNSE, IntWallW, IntWallNW, IntWallSW, IntWallNSW,
    IntWallEW, IntWallNEW, IntWallSEW, IntWallNSEW};

    enum button {Play1, Play2, Playe3, Exit1, Exit2, Exit3,
    Settings1, Settings2, Settings3, How1, How2, How3,
    Wheel1, Wheel2, Wheel3, LArrow1, LArrow2, LArrow3,
    RArrow1, RArrow2, RArrow3};
    static const sfIntRect button_rect[NBR_BUTTON] = {
        {1344, 0, 128, 64}, {1472, 0, 128, 64}, {1600, 0, 128, 64},
        {1344, 64, 128, 64}, {1472, 64, 128, 64}, {1600, 64, 128, 64},
        {1344, 128, 128, 64}, {1472, 128, 128, 64}, {1600, 128, 128, 64},
        {1344, 192, 128, 64}, {1472, 192, 128, 64}, {1600, 192, 128, 64},
        {1728, 0, 64, 64}, {1792, 0, 64, 64}, {1856, 0, 64, 64},
        {1728, 192, 64, 64}, {1792, 192, 64, 64}, {1856, 192, 64, 64},
        {1728, 128, 64, 64}, {1792, 128, 64, 64}, {1856, 128, 64, 64}};

    static const sfIntRect wall_rect[NBR_WALL] = {
        {64, 0, 64, 64}, {64, 64, 64, 64}, {64, 128, 64, 64},
        {64, 192, 64, 64}, {64, 256, 64, 64}, {64, 320, 64, 64},
        {64, 384, 64, 64}, {64, 448, 64, 64}, {64, 512, 64, 64},
        {64, 576, 64, 64}, {64, 640, 64, 64}, {64, 704, 64, 64},
        {64, 768, 64, 64}, {64, 832, 64, 64}, {64, 896, 64, 64},
        {64, 960, 64, 64},
        {128, 0, 64, 64}, {128, 64, 64, 64}, {128, 128, 64, 64},
        {128, 192, 64, 64}, {128, 256, 64, 64}, {128, 320, 64, 64},
        {128, 384, 64, 64}, {128, 448, 64, 64}, {128, 512, 64, 64},
        {128, 576, 64, 64}, {128, 640, 64, 64}, {128, 704, 64, 64},
        {128, 768, 64, 64}, {128, 832, 64, 64}, {128, 896, 64, 64},
        {128, 960, 64, 64}
    };

    enum player {PlayerGun1, PlayerGun2, PlayerGun3, PlayerGun4,
    PlayerRifle1, PlayerRifle2, PlayerRifle3, PlayerRifle4};
    static const sfIntRect player_rect[NBR_PLAYER] = {{192, 0, 64, 64}, {256, 0, 64, 64},
    {320, 0, 64, 64}, {384, 0, 64, 64}, {192, 64, 64, 64},
    {256, 64, 64, 64}, {320, 64, 64, 64}, {384, 64, 64, 64}};

    enum shirt {TankRifle, TankGun, BlackRifle, BlackGun,
    FlowerRifle, FlowerGun, FireRifle, FireGun};
    static const sfIntRect shirt_rect[NBR_SHIRT] = {{640, 0, 64, 64}, {704, 0, 64, 64},
    {640, 64, 64, 64}, {704, 64, 64, 64}, {640, 128, 64, 64},
    {740, 128, 64, 64}, {640, 192, 64, 64}, {704, 192, 64, 64}};
    static int shirt_swag[4] = {1, 5, 15, 25};

    enum hat {BlackCap, BlackDourag, FireCap};
    static const sfIntRect hat_rect[NBR_HAT] = {{768, 0, 64, 64}, {768, 64, 64, 64},
    {768, 128, 64, 64}};
    static int hat_swag[3] = {3, 15, 20};

    enum pants {BlueGun1, BlueGun2, BlueGun3, BlueGun4,
    BlueRifle1, BlueRifle2, BlueRifle3, BlueRifle4,
    BlackGun1, BlackGun2, BlackGun3, BlackGun4,
    BlackRifle1, BlackRifle2, BlackRifle3, BlackRifle4};
    static const sfIntRect pants_rect[NBR_PANTS] = {{832, 0, 64, 64}, {896, 0, 64, 64},
    {960, 0, 64, 64}, {1024, 0, 64, 64}, {1088, 0, 64, 64}, {1152, 0, 64, 64},
    {1216, 0, 64, 64}, {1280, 0, 64, 64}, {832, 64, 64, 64}, {896, 64, 64, 64},
    {960, 64, 64, 64}, {1024, 64, 64, 64}, {1088, 64, 64, 64},
    {1152, 64, 64, 64}, {1216, 64, 64, 64}, {1280, 64, 64, 64}};
    static int pants_swag[2] = {1, 2};

    enum enemies {EnemyGun1, EnemyGun2, EnemyGun3,
    EnemyGlock1, EnemyGlock2, EnemyGlock3,
    EnemyShotgun1, EnemyShotgun2, EnemyShotgun3};
    static const sfIntRect enemies_rect[NBR_ENEMIES] = {{448, 0, 64, 64}, {512, 0, 64, 64},
    {576, 0, 64, 64}, {448, 64, 64, 64}, {512, 64, 64, 64},
    {576, 64, 64, 64}, {448, 256, 64, 64}, {512, 256, 64, 64},
    {576, 256, 64, 64}};

    enum weapon {Gun, M4, Sniper};
    static const sfIntRect weapon_rect[NBR_WEAPON] = {{192, 128, 64, 64}, {256, 128, 64, 64},
    {256, 192, 64, 64}};
    static const int gun_damage[3][4] = {{9, 24, 2.3, 1.3},
    {30, 33, 0.1, 3.1}, {10, 88, 1.25, 3.37}};

    static const int swag[] = {15, 25, 5, 1, 3, 15, 20};

#endif
