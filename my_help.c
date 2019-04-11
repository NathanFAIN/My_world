/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu
*/

#include "my.h"

void my_test_save(map_t *m)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_drawSprite(m->window, m->button[10]->sprite1, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    sfClock_getElapsedTime(m->clock).microseconds / 500000.0 > 1.0) {
        save(m->map_3d, m->text_box);
        sfClock_restart(m->clock);
    }
}

void my_test_help(map_t *m)
{
    if (m->m_x > m->button[7]->pos.x && m->m_x < m->button[7]->pos.x + 49 && \
    m->m_y > m->button[7]->pos.y && m->m_y < m->button[7]->pos.y + 49) {
            sfRenderWindow_drawSprite(m->window, m->button[8]->sprite1, NULL);
            sfSprite_setTexture(m->button[7]->sprite1, m->button[7]->texture2, \
            sfTrue);
    } else
        sfSprite_setTexture(m->button[7]->sprite1, m->button[7]->texture1, \
        sfTrue);
    sfRenderWindow_drawSprite(m->window, m->button[7]->sprite1, NULL);
    sfRenderWindow_drawSprite(m->window, m->button[7]->sprite2, NULL);
    sfRenderWindow_drawSprite(m->window, m->button[9]->sprite1, NULL);
    if (m->m_x > m->button[9]->pos.x && m->m_x < m->button[9]->pos.x + 49 && \
    m->m_y > m->button[9]->pos.y && m->m_y < m->button[9]->pos.y + 49) {
            sfSprite_setTexture(m->button[9]->sprite1, m->button[9]->texture2, \
            sfTrue);
            my_test_save(m);
    } else
        sfSprite_setTexture(m->button[9]->sprite1, m->button[9]->texture1, \
        sfTrue);
    sfRenderWindow_drawSprite(m->window, m->button[9]->sprite2, NULL);
}

void create_help(map_t *map)
{
    map->button[7] = create_obj("img/blue_button1.png", \
    "img/blue_button2.png", "img/point.png", (sfVector2f) {100, 900});
    map->button[8] = create_obj("img/help.png", \
    "img/help.png", "img/help.png", (sfVector2f) {0, 0});
    map->button[9] = create_obj("img/blue_button1.png", \
    "img/blue_button2.png", "img/save.png", (sfVector2f) {1700, 900});
    map->button[10] = create_obj("img/green_button2.png", \
    "img/green_button1.png", "img/green_button2.png", (sfVector2f) {1700, 900});
}
