/*
** EPITECH PROJECT, 2019
** map
** File description:
** map
*/

#include "my.h"

void my_put_float(float nb, int fd)
{
    int a = nb;
    int b = 0;
    float c = 1;

    c = !a ? 10 : 1;
    for (; a > 0; c *= 10)
        a /= 10;
    for (c = c / 10; c >= 0.001; c /= 10) {
        a = (nb / c) - (b * 10);
        b *= 10;
        b += a;
        a += 48;
        write(fd, &a, 1);
        c == 1 ? write(fd, ".", 1) : 0;
    }
}

void create_txt(char *name)
{
    int fd = open(name, O_RDWR);
    FILE* file;

    if (fd >= 0)
        close(fd);
    else {
        file = fopen(name, "wr");
        if (file)
            fclose(file);
    }
}

void save(float **map, char *file)
{
    int fd;

    create_txt(file);
    fd = open(file, O_WRONLY);
    if (fd == -1)
        return;
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            my_put_float(map[i][j], fd);
            j < MAP_X - 1 ? write(fd, " ", 1) : 0;
        }
        write(fd, "\n", 1);
    }
    close(fd);
}

float read_fl(int fd)
{
    float ans = 0;
    char buf[1];

    while (read(fd, buf, 1) && *buf != '.') {
        ans *= 10;
        ans += (*buf - 48);
    }
    for (float d = 0.1; read(fd, buf, 1) && *buf != ' ' && *buf != '\n';
    d /= 10)
        ans += ((*buf - 48) * d);
    return (ans);
}

float **load(char *file)
{
    int fd = open(file, O_RDONLY);
    float **ans = malloc(sizeof(float *) * (MAP_Y + 1));

    for (int i = 0; i < MAP_Y; i++)
        ans[i] = malloc(sizeof(float) * MAP_X);
    ans[MAP_Y] = NULL;
    for (int i = 0; i < MAP_Y; i++)
        for (int j = 0; j < MAP_X; j++)
            ans[i][j] = read_fl(fd);
    close(fd);
    return (ans);
}
