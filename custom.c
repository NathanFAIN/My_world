/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void update_color(map_t *map, int x, int y, float n)
{
    if (!(x - 1 >= 0 && x + 1 < MAP_X && y - 1 >= 0 && y + 1 < MAP_Y) || \
    map->map_3d[y][x] + n <= 0 || map->map_3d[y][x] + n >= 30)
        return;
    map->map_3d[y][x] += n;
    set_color(map, x, y);
    if (y < 2 || x < 2 || y > MAP_Y - 3 || x > MAP_X - 3)
        map->color[y][x] = sfColor_fromRGBA(91, 66, 25, 255);
}

void update_2d_map(map_t *map, float n, int m)
{
    int y;
    int x;

    if (map->tmp.x == -1)
        return;
    y = (map->tmp.y - m / 2 >= 2) ? map->tmp.y - m / 2 : 1;
    for (; y < MAP_Y - 1 && y < map->tmp.y + m / 2; y++)
        for (x = (map->tmp.x - m / 2 >= 2) ? map->tmp.x - m / 2 : 1; x < MAP_X \
        - 1 && x < map->tmp.x + m / 2; x++)
            update_color(map, x, y, n);

}

sfVector2f my_custom3(map_t *map, int i, int j)
{
    sfVector2f a = project_vertex((j - MAP_X / 2) * 5 * map->zoom, \
    map->map_3d[i][j] * 10 * map->zoom, (i - MAP_Y / 2) * 5 * map->zoom, map);

    return (a);
}

int my_custom2(map_t *map, int i, int j, int t)
{
    float x = map->m_x;
    float y = map->m_y;
    sfVector2f a = my_custom3(map, i, j);
    sfVector2f b = my_custom3(map, i, j + 1);
    sfVector2f c = my_custom3(map, i + 1, j + 1);
    sfVector2f d = my_custom3(map, i + 1, j);

    t = (x + 2 >= a.x && y + 2 >= a.y && x <= d.x + 2 && y <= d.y + 2) ? 0 : t;
    t = (x + 2 >= b.x && y + 2 >= b.y && x <= c.x + 2 && y <= c.y + 2) ? 0 : t;
    t = (x <= a.x + 2 && y <= a.y + 2 && x >= d.x + 2 && y >= d.y + 2) ? 0 : t;
    t = (x <= b.x + 2 && y <= b.y + 2 && x >= c.x + 2 && y >= c.y + 2) ? 0 : t;
    t = (x + 2 >= a.x && y + 2 >= b.y && x <= c.x + 2 && y <= d.y + 2) ? 0 : t;
    t = (x + 2 >= b.x && y + 2 >= a.y && x <= d.x + 2 && y <= c.y + 2) ? 0 : t;
    t = (x <= a.x + 2 && y <= b.y + 2 && x >= c.x + 2 && y >= d.y + 2) ? 0 : t;
    t = (x <= b.x + 2 && y <= a.y + 2 && x >= d.x + 2 && y >= c.y + 2) ? 0 : t;
    return (t);
}

sfVector2f my_custom(map_t *map)
{
    int test = 1;
    int i = 1;
    int j;

    map->m_x = sfMouse_getPositionRenderWindow(map->window).x;
    map->m_y = sfMouse_getPositionRenderWindow(map->window).y;
    for (; i < MAP_Y - 1 && test; i++)
        for (j = 1; j < MAP_X - 1 && test; j++) {
            test = my_custom2(map, i, j, test);
        }
    return (j == MAP_X - 1 && i == MAP_Y - 1 ? (sfVector2f) {-1, -1}  : \
    (sfVector2f) {j, i});
}
