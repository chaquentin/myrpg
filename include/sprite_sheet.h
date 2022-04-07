/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** sprite_sheet
*/

#ifndef SPRITE_SHEET_H_
    #define SPRITE_SHEET_H_

    #include "SFML/Graphics.h"

    #define ALL_SPRITES 27
    #define PI 3.1415926535
    #define HEAD 0
    #define TOP 1

    enum all_sprites {WoodenFloor, WallBL, WallBR, WallUL, WallUR, WallB,
    WallBM, WallUM, WallRM, WallLM, WallL,
    NiggerRifle, NiggerGun,
    FireShirtGun, FireShirtRifle,
    FlowerShirtGun, FlowerShirtRifle,
    BlackShirtGun, BlackShirtRifle,
    TankTopShirtGun, TankTopShirtRifle,
    BlackCap, BlackDourag, FireCap,
    Gun, M4, Sniper};

    enum decor {WoodenFloor, WallBL, WallBR, WallUL, WallUR, WallB,
    WallBM, WallUM, WallRM, WallLM, WallL};

    enum nigger {NiggerRifle, NiggerGun};
    
    static const int swag[] = {15, 25, 5, 1, 3, 15, 20};
    enum clothes {FireShirt_c, FlowerShirt_c, BlackShirt_c, TankTopShirt_c,
    BlackCap_c, BlackDourag_c, FireCap_c};

    static const int gun_damage[3][4] = {{9, 24, 2.3, 1.3}, {30, 33, 0.1, 3.1},
    {10, 88, 1.25, 3.37}};
    enum weapon {Gun_w, M4_w, Sniper_w};

    static const sfIntRect all_rect[27] = {{0, 0, 64, 64}, {64, 0, 64, 64},
    {128, 0, 64, 64}, {192, 0, 64, 64}, {256, 0, 64, 64}, {320, 0, 64, 64},
    {384, 0, 64, 64}, {448, 0, 64, 64}, {512, 0, 64, 64}, {576, 0, 64, 64},
    {640, 0, 64, 64},
    {0, 64, 64, 64}, {64, 64, 64, 64},
    {128, 64, 64, 64}, {192, 64, 64, 64},
    {256, 64, 64, 64}, {320, 64, 64, 64},
    {384, 64, 64, 64}, {448, 64, 64, 64},
    {512, 64, 64, 64}, {576, 64, 64, 64},
    {640, 64, 64, 64}, {704, 64, 64, 64}, {768, 64, 64, 64},
    {0, 128, 64, 64}, {64, 128, 64, 64}, {128, 128, 64, 64}};

#endif
