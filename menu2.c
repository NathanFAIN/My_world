/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu
*/

#include "my.h"

char *nbr_str(long nb)
{
    char *str = malloc(16);
    long i = -1;

    for (int i = 0; i < 13; i++)
        str[i] = (i == 0) ? '0' : '\0';
    for (long compt =  nb; compt >= 1; i++)
        compt = compt / 10;
    for (; nb >= 1; i--) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    return (str);
}

void create_text(map_t *map)
{
    map->txt = malloc(sizeof(sfText *) * 6);
    for (int i = 0; i < 2; i++) {
        map->txt[i] = sfText_create();
        sfText_setFont(map->txt[i], sfFont_createFromFile("img/sc.ttf"));
        sfText_setString(map->txt[i], "0");
        sfText_setColor(map->txt[i], sfBlack);
        sfText_setCharacterSize(map->txt[i], 100);
    }
    for (int i = 2; i < 5; i++) {
        map->txt[i] = sfText_create();
        sfText_setFont(map->txt[i], sfFont_createFromFile("img/font.ttf"));
        sfText_setColor(map->txt[i], sfBlack);
        sfText_setCharacterSize(map->txt[i], 30);
    }
    sfText_setString(map->txt[2], "ROUGHNESS");
    sfText_setString(map->txt[3], "DEPTH");
    sfText_setPosition(map->txt[0], (sfVector2f) {1250, 350});
    sfText_setPosition(map->txt[1], (sfVector2f) {1250, 550});
    sfText_setPosition(map->txt[2], (sfVector2f) {1020, 360});
    sfText_setPosition(map->txt[3], (sfVector2f) {1020, 560});
}

void resize_menu(map_t *map)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    if (map->m_x > map->m[1]->pos.x && map->m_x < map->m[1]->pos.x + 180 && \
        map->m_y > map->m[1]->pos.y && map->m_y < map->m[1]->pos.y + 49) {
            map->m[1]->pos2.x = map->m_x;
            map->freq = ((map->m[1]->pos2.x / (map->m[1]->pos.x + 180)) * 0.05 \
            - 0.04) * 10 - 0.01;
    }
    if (map->m_x > map->m[2]->pos.x && map->m_x < map->m[2]->pos.x + 180 && \
        map->m_y > map->m[2]->pos.y && map->m_y < map->m[2]->pos.y + 49) {
            map->m[2]->pos2.x = map->m_x;
            map->eq = ((map->m[2]->pos.x + 180 - map->m[2]->pos2.x) * 0.1);
    }
    sfSprite_setPosition(map->m[1]->sprite2, map->m[1]->pos2);
    sfSprite_setPosition(map->m[2]->sprite2, map->m[2]->pos2);
}
