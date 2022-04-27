/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-luca.deltort
** File description:
** my_atoi
*/

static int my_pow10(int value, int pow)
{
    for (; pow > 1; pow--)
        value *= 10;
    return (value);
}

int my_atoi(char *str_ptr)
{
    int result = 0;
    int i = 0;

    if (str_ptr[0] < 48 || str_ptr[0] > 57)
        return (-1);
    for (; str_ptr[i] > 47 && str_ptr[i] < 58; i++)
        str_ptr[i] -= 48;
    for (int j = 0; i > 0; j++) {
        result += my_pow10(str_ptr[j], i);
        i--;
    }
    return (result);
}
