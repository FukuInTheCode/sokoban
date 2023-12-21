/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int verify_containing(char *map)
{
    int error = 0;
    int count_p = 0;
    int count_x = 0;
    int count_o = 0;

    for (int i = 0; map[i]; i++) {
        count_p += map[i] == 'P';
        count_x += map[i] == 'X';
        count_o += map[i] == 'O';
    }
    error |= 84 * (count_p == 0 || count_x == 0 || count_x != count_o);
    return error;
}

static int verify_map(char *map)
{
    int m = 0;
    int error = 0;

    for (int i = 0; map[i++]; (map[i - 1] == '\n') && m++);
    m += (map[my_strlen(map) - 1] != '\n');
    for (int i = 0; map[i]; i++)
        error |= 84 * (map[i] != '#' && map[i] != ' ' && map[i] != 'O' &&
            map[i] != 'X' && map[i] != '\n' && map[i] != 'P');
    error |= verify_containing(map);
    return error;
}

static int read_file(char const *path)
{
    int error = 0;
    int fd = open(path, O_RDONLY);
    char *buf = NULL;
    struct stat s;

    if (fd < 0 || stat(path, &s))
        return 84;
    buf = malloc(s.st_size + 1);
    if (!buf)
        return 84;
    for (size_t i = 0; i++ < s.st_size + 1; buf[i - 1] = 0);
    for (int64_t len = read(fd, buf + my_strlen(buf),
        s.st_size - my_strlen(buf)); len > 0;
        len = read(fd, buf + my_strlen(buf), s.st_size - my_strlen(buf)));
    printf("%s\n", buf);
    error |= verify_map(buf);
    free(buf);
    return error;
}

int main(int argc, char **argv)
{
    int error = 0;

    if (argc != 2)
        return 84;
    error |= read_file(argv[1]);
    return error;
}
