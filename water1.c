/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void draw_water1(sfVector3f p1, sfVector3f p2, sfVector3f p3, map_t *map)
{
    sfColor b = sfColor_fromRGBA(0, 204, 255, 100);
    sfVertex v1 = (sfVertex) {.position = project_vertex((p1.x - MAP_X / 2) * \
    5 * map->zoom, map->water_size * 10 * map->zoom, (p1.z - MAP_Y / 2) * 5 * \
    map->zoom, map), .color = b};
    sfVertex v2 = (sfVertex) {.position = project_vertex((p2.x - MAP_X / 2) * \
    5 * map->zoom, map->water_size * 10 * map->zoom, (p2.z - MAP_Y / 2) * 5 * \
    map->zoom, map), .color = b};
    sfVertex v3 = (sfVertex) {.position = project_vertex((p3.x - MAP_X / 2) * \
    5 * map->zoom, map->water_size * 10 * map->zoom, (p3.z - MAP_Y / 2) * 5 * \
    map->zoom, map), .color = b};

    sfVertexArray_clear(map->vertex);
    sfVertexArray_append(map->vertex, v3);
    sfVertexArray_append(map->vertex, v2);
    sfVertexArray_append(map->vertex, v1);
    sfVertexArray_setPrimitiveType(map->vertex, sfTriangles);
    sfRenderWindow_drawVertexArray(map->window, map->vertex, NULL);
}

void draw_face1(int i, int j, map_t *map, sfVector3f p[])
{
    if (map->water_size >= map->map_3d[j][i])
        draw_water1(p[0], intersection_point(map, p[0], p[3]), \
        intersection_point(map, p[0], p[1]), map);
    if (map->water_size >= map->map_3d[j + 1][i])
        draw_water1(p[1], intersection_point(map, p[1], p[0]), \
        intersection_point(map, p[1], p[2]), map);
    if (map->water_size >= map->map_3d[j + 1][i + 1])
        draw_water1(p[2], intersection_point(map, p[2], p[1]), \
        intersection_point(map, p[2], p[3]), map);
    if (map->water_size >= map->map_3d[j][i + 1])
        draw_water1(p[3], intersection_point(map, p[3], p[2]), \
        intersection_point(map, p[3], p[0]), map);
}

void draw_water2(sfVector3f p[], map_t *m)
{
    sfColor b = sfColor_fromRGBA(0, 204, 255, 100);

    sfVertexArray_clear(m->vertex);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(m->vertex, (sfVertex) {.position = \
        project_vertex((p[i].x - MAP_X / 2) * 5 * m->zoom, m->water_size * \
        10 * m->zoom, (p[i].z - MAP_Y / 2) * 5 * m->zoom, m), .color = b});
    sfVertexArray_setPrimitiveType(m->vertex, sfQuads);
    sfRenderWindow_drawVertexArray(m->window, m->vertex, NULL);
}

void draw_face222(map_t *map, sfVector3f p[], sfVector3f po[])
{
    if (map->water_size < p[0].y && map->water_size < p[1].y) {
        po[0] = p[2];
        po[1] = intersection_point(map, p[2], p[1]);
        po[2] = intersection_point(map, p[3], p[0]);
        po[3] = p[3];
        draw_water2(po, map);
        return;
    } else if (map->water_size < p[1].y && map->water_size < p[2].y) {
        po[0] = p[3];
        po[1] = intersection_point(map, p[3], p[2]);
        po[2] = intersection_point(map, p[0], p[1]);
        po[3] = p[0];
        draw_water2(po, map);
        return;
    }
}

void draw_face22(map_t *map, sfVector3f p[])
{
    sfVector3f po[4];

    if (map->water_size < p[2].y && map->water_size < p[3].y) {
        po[0] = p[0];
        po[1] = intersection_point(map, p[0], p[3]);
        po[2] = intersection_point(map, p[1], p[2]);
        po[3] = p[1];
        draw_water2(po, map);
        return;
    } else if (map->water_size < p[3].y && map->water_size < p[0].y) {
        po[0] = p[1];
        po[1] = intersection_point(map, p[1], p[0]);
        po[2] = intersection_point(map, p[2], p[3]);
        po[3] = p[2];
        draw_water2(po, map);
        return;
    }
    draw_face222(map, p, po);
}
