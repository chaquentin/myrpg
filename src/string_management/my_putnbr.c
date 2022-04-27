/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** my_putnbr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnbr(int nbr, char c)
{
    int nbr2;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 10) {
        nbr2 = nbr % 10;
        nbr = nbr / 10;
        my_putnbr(nbr, 0);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
    my_putchar(c);
    return (0);
}
