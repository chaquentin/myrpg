/*
** EPITECH PROJECT, 2022
** myrpg-200
** File description:
** is_in
*/

int is_in(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}
