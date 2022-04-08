/*
** EPITECH PROJECT, 2022
** my_is_alpha
** File description:
** verify_if_it_is_alpha_character
*/

int is_parser(char c, char *to_compare)
{
    for (int i = 0; to_compare[i]; i++)
        if (c == to_compare[i])
            return 0;
    return 1;
}
