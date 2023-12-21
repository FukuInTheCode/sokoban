/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int find_y(char *map, int id, int dy)
{
    int i = id;
    int j = 0;

    for (; i > 0 && map[i - 1] != '\n';)
        i--;
    if (dy < 0)
        for (j = i - 1; j > 0 && map[j - 1] != '\n';)
            j--;
    if (dy > 0)
        for (j = i + 1; map[j - 1] && map[j - 1] != '\n';)
            j++;
    return id + j - i;
}

static bool handle_win(char *map, char *base_map)
{
    for (int i = 0; base_map[i]; i++)
        if (base_map[i] == 'O' && map[i] != 'X')
            return false;
    return true;
}

static bool check_is_blocked(char *map, int i)
{
    if (map[i + 1] == '#' && map[find_y(map, i, 1)] == '#')
        return true;
    if (map[i + 1] == '#' && map[find_y(map, i, -1)] == '#')
        return true;
    if (map[i - 1] == '#' && map[find_y(map, i, -1)] == '#')
        return true;
    if (map[i - 1] == '#' && map[find_y(map, i, 1)] == '#')
        return true;
    return false;
}

static bool handle_lose(char *map)
{
    int blocked = 0;
    int box = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] != 'X')
            continue;
        box++;
        blocked += check_is_blocked(map, i);
    }
    if (blocked == box)
        return true;
    return false;
}

int handle_end(char *map, char *base_map)
{
    if (handle_win(map, base_map))
        return 1;
    if (handle_lose(map))
        return 2;
    return 0;
}
