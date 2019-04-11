/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void set_button2(map_t *m)
{
    sfSprite_setTexture(m->button[4]->sprite1, m->button[4]->texture1, sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 20 && m->m_y < 70 \
    && m->pen[0])
        sfSprite_setTexture(m->button[4]->sprite1, m->button[4]->texture2, \
        sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 80 && m->m_y < 130 \
    && m->pen[1])
        sfSprite_setTexture(m->button[4]->sprite1, m->button[4]->texture2, \
        sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 140 && m->m_y < 190 \
    && m->pen[2])
        sfSprite_setTexture(m->button[4]->sprite1, m->button[4]->texture2, \
        sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 200 && m->m_y < 250 \
    && m->pen[3])
        sfSprite_setTexture(m->button[4]->sprite1, m->button[4]->texture2, \
        sfTrue);
}

void set_button(map_t *m)
{
    for (int i = 0; i < 4; i++)
        sfSprite_setTexture(m->button[i]->sprite1, \
        m->button[i]->texture1, sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 20 && m->m_y < 70)
        for (int i = 0; i < 4; i++)
            sfSprite_setTexture(m->button[i]->sprite1, (i != 0) ? \
            m->button[i]->texture1 : m->button[i]->texture2, sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 80 && m->m_y < 130)
        for (int i = 0; i < 4; i++)
            sfSprite_setTexture(m->button[i]->sprite1, (i != 1) ? \
            m->button[i]->texture1 : m->button[i]->texture2, sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 140 && m->m_y < 190)
        for (int i = 0; i < 4; i++)
            sfSprite_setTexture(m->button[i]->sprite1, (i != 2) ? \
            m->button[i]->texture1 : m->button[i]->texture2, sfTrue);
    if (m->m_x > 1700 && m->m_x < 1750 && m->m_y > 200 && m->m_y < 250)
        for (int i = 0; i < 4; i++)
            sfSprite_setTexture(m->button[i]->sprite1, (i != 3) ? \
            m->button[i]->texture1 : m->button[i]->texture2, sfTrue);
    set_button2(m);
}

void set_pen(map_t *map)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    if (map->m_x > 1700 && map->m_x < 1750 && map->m_y > 20 && map->m_y < 70)
        for (int i = 0; i < 4; i++)
            map->pen[i] = (i == 0) ? 1 : 0;
    if (map->m_x > 1700 && map->m_x < 1750 && map->m_y > 80 && map->m_y < 130)
        for (int i = 0; i < 4; i++)
            map->pen[i] = (i == 1) ? 1 : 0;
    if (map->m_x > 1700 && map->m_x < 1750 && map->m_y > 140 && map->m_y < 190)
        for (int i = 0; i < 4; i++)
            map->pen[i] = (i == 2) ? 1 : 0;
    if (map->m_x > 1700 && map->m_x < 1750 && map->m_y > 200 && map->m_y < 250)
        for (int i = 0; i < 4; i++)
            map->pen[i] = (i == 3) ? 1 : 0;
}

void draw_button(map_t *m)
{
    set_pen(m);
    set_button(m);
    for (int i = 0; i < 4; i++) {
        if (m->pen[i]) {
            sfSprite_setPosition(m->button[4]->sprite1, m->button[i]->pos);
            sfRenderWindow_drawSprite(m->window, m->button[4]->sprite1, NULL);
        } else
            sfRenderWindow_drawSprite(m->window, m->button[i]->sprite1, NULL);
        sfRenderWindow_drawSprite(m->window, m->button[i]->sprite2, NULL);
    }
    draw_resize_pen(m);
}

map_t *create_button(map_t *map)
{
    map->button = malloc(sizeof(obj_t *) * 11);
    map->button[0] = create_obj("img/blue_button1.png", \
    "img/blue_button2.png", "img/pen.png", (sfVector2f) {1700, 20});
    map->button[1] = create_obj("img/blue_button1.png", \
    "img/blue_button2.png", "img/brush.png", (sfVector2f) {1700, 80});
    map->button[2] = create_obj("img/blue_button1.png", \
    "img/blue_button2.png", "img/bulldozer.png", (sfVector2f) {1700, 140});
    map->button[3] = create_obj("img/blue_button1.png", \
    "img/blue_button2.png", "img/recycle.png", (sfVector2f) {1700, 200});
    map->button[4] = create_obj("img/green_button1.png", \
    "img/green_button2.png", "img/recycle.png", (sfVector2f) {1700, 310});
    create_help(map);
    for (int i = 0; i < 4; i++)
        map->pen[i] = (!i) ? 1 : 0;
    return (create_resize_pen(map));
}
