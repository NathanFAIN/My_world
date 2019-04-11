/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void smooth_map(map_t *map, int m, int x, int y)
{
    if (map->map_3d[y][x] > m)
        update_color(map, x, y, -0.5 * (map->map_3d[y][x] / m));
    if (map->map_3d[y][x] < m)
        update_color(map, x, y, 0.6 * (m / map->map_3d[y][x]));
}

void smooth2(map_t *map, int n, int m)
{
    int y;
    int x;

    y = (map->tmp.y - n / 2 >= 2) ? map->tmp.y - n / 2 : 1;
    for (; y < MAP_Y - 1 && y < map->tmp.y + n / 2; y++)
        for (x = (map->tmp.x - n / 2 >= 2) ? map->tmp.x - n / 2 : 1; x < MAP_X \
        - 1 && x < map->tmp.x + n / 2; x++)
            smooth_map(map, m, x, y);
}

void set_smooth(map_t *map, int n)
{
    int compt = 0;
    int m = 0;
    int y;
    int x;

    if (map->tmp.x == -1 || !sfMouse_isButtonPressed(sfMouseLeft))
        return;
    y = (map->tmp.y - n / 2 >= 2) ? map->tmp.y - n / 2 : 1;
    for (; y < MAP_Y - 1 && y < map->tmp.y + n / 2; y++)
        for (x = (map->tmp.x - n / 2 >= 2) ? map->tmp.x - n / 2 : 1; x \
        < MAP_X - 1 && x < map->tmp.x + n / 2; x++)
            compt++;
    if (!compt)
        return;
    y = (map->tmp.y - n / 2 >= 2) ? map->tmp.y - n / 2 : 1;
    for (; y < MAP_Y - 1 && y < map->tmp.y + n / 2; y++)
        for (x = (map->tmp.x - n / 2 >= 2) ? map->tmp.x - n / 2 : 1; x \
        < MAP_X - 1 && x < map->tmp.x + n / 2; x++)
            m += map->map_3d[y][x];
    smooth2(map, n, m / compt);
}
