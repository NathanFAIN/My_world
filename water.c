/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void draw_face0(int x, int y, map_t *map)
{
    sfColor b = sfColor_fromRGBA(0, 204, 255, 100);

    sfVertexArray_clear(map->vertex);
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex((x - MAP_X / 2) * 5 * map->zoom, map->water_size * 10000 \
    * map->zoom / 1000, (y - MAP_Y / 2) * 5 * map->zoom, map), .color = b});
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex(((x + 1) - MAP_X / 2) * 5 * map->zoom, \
    map->water_size * 10000 * map->zoom / 1000, (y - MAP_Y / 2) * 5 * \
    map->zoom, map), .color = b});
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex(((x + 1) - MAP_X / 2) * 5 * map->zoom, \
    map->water_size * 10000 * map->zoom / 1000, ((y + 1) - \
    MAP_Y / 2) * 5 * map->zoom, map), .color = b});
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex((x - MAP_X / 2) * 5 * map->zoom, map->water_size * \
    10000 * map->zoom / 1000, ((y + 1) - MAP_Y / 2) * 5 * map->zoom, map), \
    .color = b});
    sfVertexArray_setPrimitiveType(map->vertex, sfTrianglesFan);
    sfRenderWindow_drawVertexArray(map->window, map->vertex, NULL);
}

sfVector3f get_vect(float x1, float y1, map_t *map)
{
    float x = x1;
    float y = map->map_3d[(int)y1][(int)x1];
    float z = y1;

    return ((sfVector3f) {x, y, z});
}

sfVector3f intersection_point(map_t *map, sfVector3f p1, sfVector3f p2)
{
    sfVector3f p;

    if (p1.x == p2.x)
        p.x = p2.x;
    else
        p.x = ((((map->water_size) - p1.y)
        * (p2.x - p1.x)) / (p2.y - p1.y)) + p1.x;
    p.y = map->water_size;
    if (p1.z == p2.z)
        p.z = p2.z;
    else
        p.z = ((((map->water_size) - p1.y)
        * (p2.z - p1.z)) / (p2.y - p1.y)) + p1.z;
    return (p);
}

int test_water(map_t *map, int i, int j)
{
    int test = 0;

    if (map->water_size < map->map_3d[j][i])
        test += 1;
    if (map->water_size < map->map_3d[j][i + 1])
        test += 1;
    if (map->water_size < map->map_3d[j + 1][i + 1])
        test += 1;
    if (map->water_size < map->map_3d[j + 1][i])
        test += 1;
    return (test);
}

void manage_water_printing(int i, int j, map_t *map)
{
    int test = test_water(map, i, j);
    sfVector3f p[4];

    if (test == 4 || i > MAP_X - 3 || i < 1 || j > MAP_Y - 3 || j < 1)
        return;
    p[0] = get_vect(i, j, map);
    p[1] = get_vect(i, j + 1, map);
    p[2] = get_vect(i + 1, j + 1, map);
    p[3] = get_vect(i + 1, j, map);
    if (test == 3)
        draw_face1(i, j, map, p);
    if (test == 2)
        draw_face22(map, p);
    if (test == 1)
        draw_face3(map, p);
    if (test == 0)
        draw_face0(i, j, map);
}
