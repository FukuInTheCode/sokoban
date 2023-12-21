/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int init_curse(char *map)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    mvprintw(0, 0, map);
    return 0;
}

static int loop_inside(char *map, int ch, char *base_map, int end_code)
{
    int has_move = 0;

    ch = getch();
    if (ch == 'q')
        return 1;
    if (ch == ' ')
        has_move = (int)my_strcpy(map, base_map) * 0 + 1;
    if (ch == KEY_LEFT)
        has_move = move_player(map, -1, 0, base_map);
    if (ch == KEY_RIGHT)
        has_move = move_player(map, 1, 0, base_map);
    if (ch == KEY_UP)
        has_move = move_player(map, 0, -1, base_map);
    if (ch == KEY_DOWN)
        has_move = move_player(map, 0, 1, base_map);
    has_move && mvprintw(0, 0, map);
    refresh();
    end_code = handle_end(map, base_map);
    return end_code;
}

int handle_game(char *map)
{
    int error = 0;
    char *base_map = my_strdup(map);

    if (!base_map)
        return 84;
    init_curse(map);
    while (1) {
        error = loop_inside(map, 0, base_map, 0);
        if (error)
            break;
    }
    endwin();
    free(base_map);
    return error - (error == 1 || error == 2);
}
