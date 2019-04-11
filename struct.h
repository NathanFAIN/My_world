/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** my structs
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct obj_s
{
    sfTexture *texture1;
    sfTexture *texture2;
    sfTexture *texture3;
    sfSprite *sprite1;
    sfSprite *sprite2;
    sfVector2f pos;
    sfVector2f pos2;
} obj_t;

typedef struct map_s
{
    obj_t **button;
    sfVector2f tmp;
    float **map_3d;
    sfVector2f **map_2d;
    sfColor **color;
    sfVertexArray *vertex;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *hand_texture;
    sfSprite *hand_sprite;
    float rotate_x;
    float rotate_y;
    float move_x;
    float move_y;
    float zoom;
    float m_x;
    float m_y;
    int pen[4];
    int pen_size;
    obj_t *resize_button;
    float freq;
    float eq;
    obj_t **m;
    sfText **txt;
    sfClock *clock;
    char *text_box;
    int water_size;
} map_t;

#endif /* STRUCT_H_ */
