/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str && str[i]; i++);
    return (i);
}

void set_map_move(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyS))
        map->move_y += 5;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        map->move_y -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        map->move_x += 5;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        map->move_x -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyPageUp) || \
    sfKeyboard_isKeyPressed(sfKeyAdd))
        map->zoom += 0.1;
    if (sfKeyboard_isKeyPressed(sfKeyPageDown) || \
    sfKeyboard_isKeyPressed(sfKeySubtract))
        map->zoom -= (map->zoom > 0.2) ? 0.1 : 0;
}

void set_map_click(map_t *map)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        update_2d_map(map, 1, map->pen_size);
    else if (sfMouse_isButtonPressed(sfMouseRight))
        update_2d_map(map, -1, map->pen_size);
}

void set_map_rotare(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        map->rotate_y += (map->rotate_y < 180) ? 0.5 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        map->rotate_y -= (map->rotate_y > 90) ? 0.5 : 0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        map->rotate_x += (map->rotate_x > 359) ? -360 : 1;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        map->rotate_x -= (map->rotate_x < 0) ? -360 : 1;
}

void my_draw_window(map_t *map)
{
    sfEvent event;

    sfRenderWindow_display(map->window);
    sfRenderWindow_clear(map->window, sfWhite);
    sfRenderWindow_drawSprite(map->window, map->sprite, NULL);
    while (sfRenderWindow_pollEvent(map->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(map->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(map->window);
    set_map_rotare(map);
    set_map_move(map);
}
