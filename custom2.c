/*
** EPITECH PROJECT, 2018
** pen.c
** File description:
** pen
*/

#include "my.h"

void set_surface(map_t *map)
{
    int tmp;

    if (map->tmp.x == -1 || !sfMouse_isButtonPressed(sfMouseLeft))
        return;
    tmp = map->map_3d[(int)map->tmp.y][(int)map->tmp.x];
    for (int y = 0; y < MAP_Y; y++)
        for (int x = 0; x < MAP_X; x++)
            map->map_3d[y][x] = tmp;
    set_side_map(map);
        for (int y = 0; y < MAP_Y; y++)
            free(map->color[y]);
        free(map->color);
        create_2d_color(map);
}

void reset_map(map_t *map)
{
    for (int y = 0; y < MAP_Y; y++)
        free(map->map_3d[y]);
    free(map->map_3d);
    for (int y = 0; y < MAP_Y; y++)
        free(map->color[y]);
    free(map->color);
    create_3d_map(map, map->freq, map->eq);
    create_2d_color(map);
    map->pen[3] = 0;
}

void custom_world(map_t *map)
{
    if (map->pen[0])
        set_map_click(map);
    if (map->pen[1])
        set_smooth(map, map->pen_size);
    if (map->pen[2])
        set_surface(map);
    if (sfClock_getElapsedTime(map->clock).microseconds / 500000.0 > 1.0 && \
    map->pen[3] && map->m_x > 1700 && map->m_x < 1750 && map->m_y > 200 && \
    map->m_y < 250 && sfMouse_isButtonPressed(sfMouseLeft)) {
        map->pen[3] = 0;
        reset_map(map);
        sfClock_restart(map->clock);
    }
    if (sfClock_getElapsedTime(map->clock).microseconds / 500000.0 > 1.0)
        map->pen[3] = 0;
}
