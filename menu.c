/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu
*/

#include "my.h"

void my_draw_menu(map_t *map)
{
    sfEvent event;

    sfRenderWindow_display(map->window);
    sfRenderWindow_clear(map->window, sfWhite);
    sfRenderWindow_drawSprite(map->window, map->sprite, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[4]->sprite1, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[0]->sprite1, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[1]->sprite1, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[2]->sprite1, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[3]->sprite1, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[1]->sprite2, NULL);
    sfRenderWindow_drawSprite(map->window, map->m[2]->sprite2, NULL);
    while (sfRenderWindow_pollEvent(map->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(map->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(map->window);
    if (!my_strlen(map->text_box))
        sfRenderWindow_drawSprite(map->window, map->m[3]->sprite2, NULL);
}

void precreate_menu(map_t *map)
{
    map->m = malloc(sizeof(obj_t) * 7);
    map->m[0] = create_obj("img/gene_button1.png", "img/gene_button2.png", \
    "img/gene_button2.png", (sfVector2f) {500, 600});
    map->m[1] = create_obj("img/resize_button3.png", "img/resize_button3.png", \
    "img/resize_button4.png", (sfVector2f) {1000, 400});
    map->m[2] = create_obj("img/resize_button3.png", "img/resize_button3.png", \
    "img/resize_button4.png", (sfVector2f) {1000, 600});
    map->m[3] = create_obj("img/box.png", "img/box.png", \
    "img/name.png", (sfVector2f) {500, 400});
    map->m[4] = create_obj("img/menu.png", "img/menu.png", \
    "img/name.png", (sfVector2f) {0, 0});
    map->m[1]->pos2 = (sfVector2f) {1000, 400};
    map->m[2]->pos2 = (sfVector2f) {1000, 600};
    sfSprite_setPosition(map->m[1]->sprite2, map->m[1]->pos2);
    sfSprite_setPosition(map->m[2]->sprite2, map->m[2]->pos2);
}

map_t *precreate_game(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->rotate_x = 45;
    map->rotate_y = 140;
    map->move_x = 60;
    map->move_y = -10;
    map->zoom = 1;
    map->freq = 0.014153;
    map->eq = 17.5;
    map->window = create_window();
    map->texture = sfTexture_createFromFile("img/sky.png", NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    create_text(map);
    precreate_menu(map);
    text_box_create(map);
    return (map);
}

int generate_button(map_t *map)
{
    map->m_x = sfMouse_getPositionRenderWindow(map->window).x;
    map->m_y = sfMouse_getPositionRenderWindow(map->window).y;

    if (map->m_x > map->m[0]->pos.x && map->m_x < map->m[0]->pos.x + 190 && \
    map->m_y > map->m[0]->pos.y && map->m_y < map->m[0 ]->pos.y + 44) {
        sfSprite_setTexture(map->m[0]->sprite1, map->m[0]->texture1, sfTrue);
        return (!sfMouse_isButtonPressed(sfMouseLeft));
    } else {
        sfSprite_setTexture(map->m[0]->sprite1, map->m[0]->texture2, sfTrue);
        return (1);
    }
}

map_t *my_menu(void)
{
    map_t *map = precreate_game();
    char *txt1;
    char *txt2;

    while (sfKeyboard_isKeyPressed(58));
    while (sfRenderWindow_isOpen(map->window) && generate_button(map) && \
    !sfKeyboard_isKeyPressed(58)) {
        txt1 = nbr_str((map->freq * 100) / 8 * 10 - 1);
        txt2 = nbr_str((19 - map->eq) / 18 * 10);
        sfText_setString(map->txt[0], txt1);
        sfText_setString(map->txt[1], txt2);
        free(txt1);
        free(txt2);
        my_draw_menu(map);
        resize_menu(map);
        print_box(map);
        for (int i = 0; i < 5; i++)
            sfRenderWindow_drawText(map->window, map->txt[i], NULL);
    }
    return (map);
}
