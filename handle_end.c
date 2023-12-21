/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int has_lost(char *map)
{
    return 0;
}

int handle_end(char *map)
{
    int count_x = 0;

    for (int i = 0; map[i]; i++)
        count_x += map[i] == 'O';
    if (!count_x)
        return 1;
    if (has_lost(map))
        return 2;
    return 0;
}
