/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int find_player(char *map)
{
    int id = 0;
    for (; map[id] != 'P'; id++);
    return id;
}

static int move_x(char *map, int dx)
{
    int id = find_player(map);

    if (map[id + dx] == ' ') {
        map[id] = ' ';
        map[id + dx] = 'P';
    }
    return 0;
}

static int move_y(char *map, int dy)
{
    int id = find_player(map);
    int i = id;
    int j = 0;
    int to = 0;

    for (; i > 0 && map[i - 1] != '\n'; i--);
    if (dy < 0)
        for (j = i - 1; j > 0 && map[j - 1] != '\n'; j--);
    if (dy > 0)
        for (j = i + 1; map[j - 1] && map[j - 1] != '\n'; j++);
    to = id + j - i;
    if (map[to] != ' ' || dy == 0)
        return 0;
    map[to] = 'P';
    map[id] = ' ';
    return 0;
}

int move_player(char *map, int dx, int dy)
{
    if (dx)
        move_x(map, dx);
    if (dy)
        move_y(map, dy);
    return 0;
}
