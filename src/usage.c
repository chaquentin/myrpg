/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** usage
*/

#include <unistd.h>

void usage(void)
{
    write(1, "USAGE\n", 6);
    write(1, "    ./my_rpg\n\n", 15);
    write(1, "DESCRIPTION\n", 13);
    write(1, "    RPG shooter in 2 dimensions.\n\n", 34);
    write(1, "KEYS\n", 5);
    write(1, "    z: move up\n", 15);
    write(1, "    s: move down\n", 17);
    write(1, "    q: move left\n", 17);
    write(1, "    d: move right\n", 18);
    write(1, "    space: interact\n", 20);
    write(1, "    escape: pause\n", 18);
    write(1, "    left click: shoot\n", 22);
    write(1, "    r: reload\n", 14);
    write(1, "    e: inventory and stats\n\n", 28);
    write(1, "OPTIONS\n", 8);
    write(1, "    -h: display this help\n", 26);
    write(1, "    -d: lauch the game in debug mode\n", 37);
}
