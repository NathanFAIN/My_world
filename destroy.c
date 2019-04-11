/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

void my_destroy_menu(map_t *map)
{
    for (int i = 0; i < 5; i++) {
        sfTexture_destroy(map->m[i]->texture1);
        sfTexture_destroy(map->m[i]->texture2);
        sfTexture_destroy(map->m[i]->texture3);
        sfSprite_destroy(map->m[i]->sprite1);
        sfSprite_destroy(map->m[i]->sprite2);
    }
    free (map->m);
    for (int i = 0; i < 5; i++)
        sfText_destroy(map->txt[i]);
    free(map->txt);
    free(map->text_box);
    sfClock_destroy(map->clock);
}

void my_destroy_button(map_t *map)
{
    for (int i = 0; i < 5; i++) {
        sfTexture_destroy(map->button[i]->texture1);
        sfTexture_destroy(map->button[i]->texture2);
        sfTexture_destroy(map->button[i]->texture3);
        sfSprite_destroy(map->button[i]->sprite1);
        sfSprite_destroy(map->button[i]->sprite2);
    }
    free (map->button);
    sfTexture_destroy(map->resize_button->texture1);
    sfTexture_destroy(map->resize_button->texture2);
    sfTexture_destroy(map->resize_button->texture3);
    sfSprite_destroy(map->resize_button->sprite1);
    sfSprite_destroy(map->resize_button->sprite2);
    sfTexture_destroy(map->hand_texture);
    sfSprite_destroy(map->hand_sprite);
}

void my_destroy(map_t *map)
{
    my_destroy_menu(map);
    my_destroy_button(map);
    sfVertexArray_destroy(map->vertex);
    for (int y = 0; y < MAP_Y; y++)
        free(map->map_2d[y]);
    free(map->map_2d);
    for (int y = 0; y < MAP_Y; y++)
        free(map->map_3d[y]);
    free(map->map_3d);
    for (int y = 0; y < MAP_Y; y++)
        free(map->color[y]);
    free(map->color);
    sfTexture_destroy(map->texture);
    sfSprite_destroy(map->sprite);
    sfRenderWindow_destroy(map->window);
    free(map);
}
