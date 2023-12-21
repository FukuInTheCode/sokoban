/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <math.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <curses.h>
    #include <grp.h>
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>


size_t my_strlen(char const *);
char *my_strdup(char const *);
char *my_strcpy(char *, char const *);
int handle_game(char *);
int handle_end(char *, char *);
int move_player(char *, int, int);

static inline int my_free(void *obj)
{
    free(obj);
    return 0;
}

static inline __attribute__((unused)) int find_y(char *map, int id, int dy)
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

#endif
