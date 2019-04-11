/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void draw_face2(int x, int y, int t, map_t *map)
{
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex((x - MAP_X / 2) * 5 * map->zoom, map->map_3d[y][x] * 10000 \
    * map->zoom / 1000, (y - MAP_Y / 2) * 5 * map->zoom, map), .color = \
    (t ? map->color[y][x] : sfRed)});
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex(((x + 1) - MAP_X / 2) * 5 * map->zoom, \
    map->map_3d[y][x + 1] * 10000 * map->zoom / 1000, (y - MAP_Y / 2) * 5 * \
    map->zoom, map), .color = (t ? map->color[y][x + 1] : sfRed)});
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex(((x + 1) - MAP_X / 2) * 5 * map->zoom, \
    map->map_3d[y + 1][x + 1] * 10000 * map->zoom / 1000, ((y + 1) - \
    MAP_Y / 2) * 5 * map->zoom, map), .color = (t ? map->color[y + 1][x + 1] : \
    sfRed)});
    sfVertexArray_append(map->vertex, (sfVertex) {.position = \
    project_vertex((x - MAP_X / 2) * 5 * map->zoom, map->map_3d[y + 1][x] * \
    10000 * map->zoom / 1000, ((y + 1) - MAP_Y / 2) * 5 * map->zoom, map), \
    .color = (t ? map->color[y + 1][x] : sfRed)});
}

void draw_face(int x, int y, map_t *map)
{
    int t;

    t = ((int) map->tmp.x == x && (int) map->tmp.y == y) ? 0 : 1;
    sfVertexArray_clear(map->vertex);
    draw_face2(x, y, t, map);
    sfVertexArray_setPrimitiveType(map->vertex, sfTrianglesFan);
    sfRenderWindow_drawVertexArray(map->window, map->vertex, NULL);
}

void set_mouse(map_t *map)
{
    sfVector2f pos;

    pos.x = sfMouse_getPositionRenderWindow(map->window).x - 12;
    pos.y = sfMouse_getPositionRenderWindow(map->window).y - 5;
    sfSprite_setPosition(map->hand_sprite, pos);
    sfRenderWindow_drawSprite(map->window, map->hand_sprite, NULL);
}

void draw_2d_map_face2( map_t *map, int n)
{
    for (int y = 0; y < MAP_Y - 1 && n == 1; y++)
        for (int x = 0; x < MAP_X - 1; x++) {
            draw_face(x, y, map);
            manage_water_printing(x, y, map);
        }
    for (int y = MAP_Y - 2; y >= 0 && n == 2; y--)
        for (int x = 0; x < MAP_X - 1; x++) {
            draw_face(x, y, map);
            manage_water_printing(x, y, map);
        }
    for (int y = MAP_Y - 2; y >= 0 && n == 3; y--)
        for (int x = MAP_X - 2; x >= 0; x--) {
            draw_face(x, y, map);
            manage_water_printing(x, y, map);
        }
    for (int y = 0; y < MAP_Y - 1 && n == 4; y++)
        for (int x = MAP_X - 2; x >= 0; x--) {
            draw_face(x, y, map);
            manage_water_printing(x, y, map);
        }
}

void draw_2d_map_face(map_t *map)
{
    int n = 3;

    map->tmp = my_custom(map);
    if (map->rotate_x <= 90 && map->rotate_x >= 0)
        n = 3;
    if (map->rotate_x <= 180 && map->rotate_x >= 90)
        n = 4;
    if (map->rotate_x <= 270 && map->rotate_x >= 180)
        n = 1;
    if (map->rotate_x <= 360 && map->rotate_x >= 270)
        n = 2;
    draw_2d_map_face2(map, n);
}
