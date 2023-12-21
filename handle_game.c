/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"
#include <curses.h>

static int init_curse(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    return 0;
}

static int loop_inside(char *map, int ch, char *base_map, int end_code)
{
    ch = getch();
    if (ch == 'q')
        return 1;
    if (ch == KEY_LEFT)
        move_player(map, -1, 0);
    if (ch == KEY_RIGHT)
        move_player(map, 1, 0);
    if (ch == KEY_UP)
        move_player(map, 0, -1);
    if (ch == KEY_DOWN)
        move_player(map, 0, 1);
    mvprintw(0, 0, map);
    end_code = handle_end(map, base_map);
    return end_code;
}

int handle_game(char *map)
{
    int error = 0;
    char *base_map = my_strdup(map);

    if (!base_map)
        return 84;
    init_curse();
    while (1) {
        error = loop_inside(map, 0, base_map, 0);
        if (error)
            break;
    }
    endwin();
    free(base_map);
    return error - (error == 1 || error == 2);
}
