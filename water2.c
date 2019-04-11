/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void draw_water3(sfVector3f p[], map_t *m)
{
    sfColor b = sfColor_fromRGBA(0, 204, 255, 100);

    sfVertexArray_clear(m->vertex);
    for (int i = 0; i < 5; i++)
        sfVertexArray_append(m->vertex, (sfVertex) {.position = \
        project_vertex((p[i].x - MAP_X / 2) * 5 * m->zoom, m->water_size * \
        10 * m->zoom, (p[i].z - MAP_Y / 2) * 5 * m->zoom, m), .color = b});
    sfVertexArray_setPrimitiveType(m->vertex, sfTrianglesFan);
    sfRenderWindow_drawVertexArray(m->window, m->vertex, NULL);
}

void draw_face33(map_t *map, sfVector3f p[], sfVector3f po[])
{
    if (map->water_size < p[2].y) {
        po[0] = p[0];
        po[1] = p[3];
        po[2] = intersection_point(map, p[3], p[2]);
        po[3] = intersection_point(map, p[2], p[1]);
        po[4] = p[1];
    }
    if (map->water_size < p[3].y) {
        po[0] = p[1];
        po[1] = p[0];
        po[2] = intersection_point(map, p[0], p[3]);
        po[3] = intersection_point(map, p[3], p[2]);
        po[4] = p[2];
    }
    draw_water3(po, map);
}

void draw_face3(map_t *map, sfVector3f p[])
{
    sfVector3f po[5];

    if (map->water_size < p[0].y) {
        po[0] = p[2];
        po[1] = p[1];
        po[2] = intersection_point(map, p[0], p[1]);
        po[3] = intersection_point(map, p[0], p[3]);
        po[4] = p[3];
    }
    if (map->water_size < p[1].y) {
        po[0] = p[3];
        po[1] = p[2];
        po[2] = intersection_point(map, p[2], p[1]);
        po[3] = intersection_point(map, p[1], p[0]);
        po[4] = p[0];
    }
    draw_face33(map, p, po);
}
