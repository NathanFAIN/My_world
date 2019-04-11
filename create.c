/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {SIZE_X, SIZE_Y, 32};
    int *rdm = malloc(sizeof(int));

    srand((long)rdm);
    free(rdm);
    window = sfRenderWindow_create(video_mode, "My World", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 100, 100, \
    sfImage_getPixelsPtr(sfImage_createFromFile("img/icon.png")));
    return (window);
}

obj_t *create_obj(const char *fd1, const char *fd2, const char *fd3, \
sfVector2f pos)
{
    obj_t *obj = malloc(sizeof(obj_t));

    obj->pos = pos;
    obj->texture1 = sfTexture_createFromFile(fd1, NULL);
    obj->texture2 = sfTexture_createFromFile(fd2, NULL);
    obj->texture3 = sfTexture_createFromFile(fd3, NULL);
    obj->sprite1 = sfSprite_create();
    obj->sprite2 = sfSprite_create();
    sfSprite_setTexture(obj->sprite1, obj->texture1, sfTrue);
    sfSprite_setTexture(obj->sprite2, obj->texture3, sfTrue);
    sfSprite_setPosition(obj->sprite1, obj->pos);
    sfSprite_setPosition(obj->sprite2, obj->pos);
    return (obj);
}

map_t *create_map(map_t *map)
{
    int fd = open(map->text_box, O_WRONLY);

    if (fd == -1)
        create_3d_map(map, map->freq, map->eq);
    else {
        close(fd);
        map->map_3d = load(map->text_box);
    }
    map->water_size = 5;
    create_2d_color(map);
    create_2d_map(map);
    map->vertex = sfVertexArray_create();
    map->hand_texture = sfTexture_createFromFile("img/hand.png", NULL);
    map->hand_sprite = sfSprite_create();
    sfSprite_setTexture(map->hand_sprite, map->hand_texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(map->window, 0);
    return (create_button(map));
}

sfVector2f project_vertex(float x, float y, float z, map_t *map)
{
    float rot = (map->rotate_x) * (M_PI / 180);
    float view = (map->rotate_y) * (M_PI / 180);
    float a = cosf(rot) * (x) - (sinf(rot) * z);
    float c = sinf(rot) * (x) + (cosf(rot) * z);
    float b = y * cosf(view) - c * sinf(view);

    return ((sfVector2f) {a + (SIZE_X / 2) - map->move_x, b + (SIZE_Y / 2) + \
    map->move_y});
}

void create_2d_map(map_t *map)
{
    map->map_2d = malloc(sizeof(sfVector2f *) * MAP_Y);
    for (int y = 0; y < MAP_Y; y++)
        map->map_2d[y] = malloc(sizeof(sfVector2f) * MAP_X);
    for (int y = 0; y < MAP_Y; y++)
        for (int x = 0; x < MAP_X; x++)
            map->map_2d[y][x] = project_vertex((x - MAP_X / 2) * 5 * \
            map->zoom, map->map_3d[y][x] * 10 * map->zoom, (y - MAP_Y / 2) \
            * 5 * map->zoom, map);
}
