/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** open_file
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int get_size(const char *path)
{
    int fd = open(path, O_RDONLY);
    int size = 0;
    char buffer[4096];
    int readen = 0;

    if (fd == -1)
        return (-1);
    readen = read(fd, buffer, 4096);
    while (readen > 0) {
        size += readen;
        readen = read(fd, buffer, 4096);
    }
    close(fd);
    return (size);
}

char *get_file(const char *path)
{
    int fd = 0;
    int size = get_size(path);
    char *str = NULL;

    if (size <= 0)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        return (NULL);
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        free(str);
        return (NULL);
    }
    read(fd, str, size);
    str[size] = '\0';
    close(fd);
    return (str);
}

char *open_file(char *path)
{
    char *buf = NULL;

    write(1, "opening levels file: ", 22);
    buf = get_file(path);
    if (buf == NULL) {
        write(1, "FAILED\n", 8);
        return NULL;
    }
    write(1, "SUCCESS\n", 9);
    return buf;
}
