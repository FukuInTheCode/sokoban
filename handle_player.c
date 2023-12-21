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

static int move_x(char *map, int dx, char *base_map)
{
    int id = find_player(map);

    if ((map[id + dx] != ' ' && map[id + dx] != 'O') || dx == 0)
        return 0;
    map[id + dx] = 'P';
    map[id] = base_map[id];
    if (base_map[id] != 'O')
        map[id] = ' ';
    return 0;
}

static int move_y(char *map, int dy, char *base_map)
{
    int id = find_player(map);
    int to = find_y(map, id, dy);

    if ((map[to] != ' ' && map[to] != 'O') || dy == 0)
        return 0;
    map[to] = 'P';
    map[id] = base_map[id];
    if (base_map[id] != 'O')
        map[id] = ' ';
    return 0;
}

int move_player(char *map, int dx, int dy, char *base_map)
{
    if (dx)
        move_x(map, dx, base_map);
    if (dy)
        move_y(map, dy, base_map);
    return 0;
}
