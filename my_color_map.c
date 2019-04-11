/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <time.h>
#include "my.h"
#include "struct.h"
#include <math.h>

void create_2d_color_side(map_t *map)
{
    for (int x = 0; x < MAP_X; x++) {
        map->color[0][x] = sfColor_fromRGBA(91, 66, 25, 255);
        map->color[1][x] = sfColor_fromRGBA(91, 66, 25, 255);
        map->color[MAP_Y - 1][x] = sfColor_fromRGBA(91, 66, 25, 255);
        map->color[MAP_Y - 2][x] = sfColor_fromRGBA(91, 66, 25, 255);
    }
    for (int y = 0; y < MAP_Y; y++) {
        map->color[y][0] = sfColor_fromRGBA(91, 66, 25, 255);
        map->color[y][1] = sfColor_fromRGBA(91, 66, 25, 255);
        map->color[y][MAP_X - 1] = sfColor_fromRGBA(91, 66, 25, 255);
        map->color[y][MAP_X - 2] = sfColor_fromRGBA(91, 66, 25, 255);
    }
}

void set_color(map_t *map, int x, int y)
{
    int tmp;

    if (map->map_3d[y][x] < map->water_size + 1 || (map->map_3d[y][x] == \
    map->water_size + 1 && rand() % 2))
        map->color [y][x] = sfColor_fromRGBA(190 + rand() % 20 - 10 + \
        map->map_3d[y][x] * 20 - 120, 190 + rand() % 20 - 10 + \
        map->map_3d[y][x] * 20 - 120, 153 + rand() % 20 - 10 + \
        map->map_3d[y][x] * 20 - 120, 255);
    else if (map->map_3d[y][x] < 8 || (map->map_3d[y][x] == 8 && rand() % 2))
        map->color [y][x] = sfColor_fromRGBA(38 + rand() % 20 - 10, \
        115 + rand() % 20 - 10 - 60 + map->map_3d[y][x] * 7, 38 + \
        rand() % 20 - 10, 255);
    else {
        tmp = 50 + rand() % 10 - 5 + map->map_3d[y][x] * 5;
        map->color [y][x] = sfColor_fromRGBA(tmp, tmp, tmp, 255);
    }
}

void create_2d_color(map_t *map)
{
    map->color = malloc(sizeof(sfColor *) * MAP_Y);
    for (int y = 0; y < MAP_Y; y++)
        map->color [y] = malloc(sizeof(sfColor) * MAP_X);
    for (int y = 0; y < MAP_Y; y++)
        for (int x = 0; x < MAP_X; x++)
            set_color(map, x, y);
    create_2d_color_side(map);
}
