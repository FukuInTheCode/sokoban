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
    int to = find_y(map, id, dy);

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
