/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

map_t *create_resize_pen(map_t *map)
{
    map->resize_button = create_obj("img/resize_button1.png", \
    "img/pen.png", "img/resize_button2.png", (sfVector2f) {1700, 260});
    map->resize_button->pos2 = (sfVector2f) {1700, 430};
    map->pen_size = (440 - map->resize_button->pos2.y) / 2 + 1;
    sfSprite_setPosition(map->resize_button->sprite2, map->resize_button->pos2);
    return (map);
}

void draw_resize_pen(map_t *map)
{
    sfRenderWindow_drawSprite(map->window, map->resize_button->sprite1, NULL);
    sfRenderWindow_drawSprite(map->window, map->resize_button->sprite2, NULL);
    if (!(map->m_x > 1700 && map->m_x < 1750 && map->m_y > 265 && map->m_y < \
    440) || !sfMouse_isButtonPressed(sfMouseLeft))
        return;
    sfSprite_setPosition(map->resize_button->sprite2, map->resize_button->pos2);
    map->resize_button->pos2.y = map->m_y;
    map->pen_size = (440 - map->m_y) / 2 + 1;
}
