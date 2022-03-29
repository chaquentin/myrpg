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
    #define PI 3.14159265358979

    enum all_sprites {WoodenFloor, WallBL, WallBR, WallUL, WallUR, WallB,
    WallBM, WallUM, WallRM, WallLM, WallL,
    Nigger1, Nigger2, Nigger3, Nigger4,
    BloodShirt1, BloodShirt2, BloodShirt3, BloodShirt4,
    FlowerShirt1, FlowerShirt2, FlowerShirt3, FlowerShirt4,
    BlackShirt1, BlackShirt2, BlackShirt3, BlackShirt4};

    static const sfIntRect all_rect[27] = {{0, 0, 64, 64}, {64, 0, 64, 64},
    {128, 0, 64, 64}, {192, 0, 64, 64}, {256, 0, 64, 64}, {320, 0, 64, 64},
    {384, 0, 64, 64}, {448, 0, 64, 64}, {512, 0, 64, 64}, {576, 0, 64, 64},
    {640, 0, 64, 64},
    {0, 64, 64, 64}, {0, 64, 64, 64}, {128, 64, 64, 64}, {192, 64, 64, 64},
    {256, 64, 64, 64}, {320, 64, 64, 64}, {384, 64, 64, 64}, {448, 64, 64, 64},
    {512, 64, 64, 64}, {576, 64, 64, 64}, {640, 64, 64, 64}, {704, 64, 64, 64},
    {768, 64, 64, 64}, {832, 64, 64, 64}, {896, 64, 64, 64}, {960, 64, 64, 64},
    };

#endif /* !SPRITE_SHEET_H_ */
