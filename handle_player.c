/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int handle_box_2(char *map, int id, int to, int type)
{
    if (to - id > 1 && type == 1 &&
        (map[find_y(map, to, 1)] == ' ' || map[find_y(map, to, 1)] == 'O')) {
        map[find_y(map, to, 1)] = 'X';
        return 0;
    }
    if (to - id < -1 && type == 1 &&
        (map[find_y(map, to, -1)] == ' ' || map[find_y(map, to, -1)] == 'O')) {
        map[find_y(map, to, -1)] = 'X';
        return 0;
    }
    return 1;
}

static int handle_box(char *map, int id, int to, int type)
{
    if (map[to] != 'X')
        return 0;
    if (to - id == 1 && type == 0 &&
        (map[to + 1] == ' ' || map[to + 1] == 'O')) {
        map[to + 1] = 'X';
        return 0;
    }
    if (to - id == -1 && type == 0 &&
        (map[to - 1] == ' ' || map[to - 1] == 'O')) {
        map[to - 1] = 'X';
        return 0;
    }
    return handle_box_2(map, id, to, type);
}

static int find_player(char *map)
{
    int id = 0;

    for (; map[id] != 'P'; id++);
    return id;
}

static int move_x(char *map, int dx, char *base_map)
{
    int id = find_player(map);

    if (id + dx >= my_strlen(map))
        return 0;
    if ((map[id + dx] != ' ' && map[id + dx] != 'O'
        && map[id + dx] != 'X') || dx == 0)
        return 0;
    if (handle_box(map, id, id + dx, 0))
        return 0;
    map[id + dx] = 'P';
    map[id] = base_map[id];
    if (base_map[id] != 'O')
        map[id] = ' ';
    return 1;
}

static int move_y(char *map, int dy, char *base_map)
{
    int id = find_player(map);
    int to = find_y(map, id, dy);

    if (to >= my_strlen(map))
        return 0;
    if ((map[to] != ' ' && map[to] != 'O' && map[to] != 'X') || dy == 0)
        return 0;
    if (handle_box(map, id, to, 1))
        return 0;
    map[to] = 'P';
    map[id] = base_map[id];
    if (base_map[id] != 'O')
        map[id] = ' ';
    return 1;
}

int move_player(char *map, int dx, int dy, char *base_map)
{
    if (dx)
        return move_x(map, dx, base_map);
    if (dy)
        return move_y(map, dy, base_map);
    return 0;
}
