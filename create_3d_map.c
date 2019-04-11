/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** my structs
*/

#include "my.h"

int smooth(double x, double y, double s)
{
    return (x + (s * s * (3-  2 * s)) * (y - x));
}

int create_z(float x, float y, int random[256])
{
    float fl_x = x - (int)x;
    float fl_y = y - (int)y;
    float v1 = random[(random[((int)y + SEED) % 256] + (int)x) % 256];
    float v2 = random[(random[((int)y + SEED + 1) % 256] + (int)x) % 256];
    float v3 = random[(random[((int)y + SEED) % 256] + (int)x + 1) % 256];
    float v4 = random[(random[((int)y + SEED + 1) % 256] + (int)x + 1) % 256];
    return (smooth(smooth(v1, v3, fl_x), smooth(v2, v4, fl_x), fl_y) * 0.1);
}

float perlin2dd(float xa, float ya, int random[256], float eq)
{
    float amp = 2.0;
    float fin = 0;

    for (int i = 0; i < eq; i++) {
        fin += create_z(xa, ya, random) * amp;
        amp /= 2;
        xa *= 2;
        ya *= 2;
    }
    return (fin / 6);
}

void set_side_map(map_t *map)
{
    for (int x = 0; x < MAP_X; x++) {
        map->map_3d[0][x] = 0;
        map->map_3d[MAP_Y - 1][x] = 0;
    }
    for (int y = 0; y < MAP_Y; y++) {
        map->map_3d[y][0] = 0;
        map->map_3d[y][MAP_X - 1] = 0;
    }
}

void create_3d_map(map_t *map, float freq, float eq)
{
    map->map_3d = malloc(sizeof(int *) * (MAP_Y + 1));
    int *random = malloc(sizeof(int) * 256);

    for (int i = 0; i < MAP_Y; i++)
        map->map_3d[i] = malloc(sizeof(int) * MAP_X);
    map->map_3d[MAP_Y] = NULL;
    for (int i = 0; i < 256; i++)
        random[i] = rand() % 255 + 1;
    for (float y = 0; y < MAP_Y; y++)
        for (float x = 0; x < MAP_X; x++)
            map->map_3d[(int)y][(int)x] = perlin2dd(x * freq, y * freq, \
            random, eq);
    free(random);
    set_side_map(map);
}
