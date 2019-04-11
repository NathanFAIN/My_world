/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
    char *rtn;
    int i = 0;
    int j = 0;

    for (; str1[i]; i++);
    for (; str2[j]; j++);
    rtn = malloc(i + j + 1);
    for (i = 0; str1[i]; i++)
        rtn[i] = str1[i];
    for (j = 0; str2[j]; j++)
        rtn[j + i] = str2[j];
    rtn[j + i] = '\0';
    return (rtn);
}

int get_key(map_t *map)
{
    char s[2];
    int i = 0;

    for (s[0] = 0; s[0] < 100 && !sfKeyboard_isKeyPressed(s[0]); s[0]++);
    s[0] += 65;
    s[1] = '\0';
    for (; map->text_box[i]; i++);
    if ((s[0] > 90 || s[0] < 65 || i >= 10) && *s != '|')
        return (0);
    if (*s != '|')
        map->text_box = my_strcat(map->text_box, s);
    else
        map->text_box[(i) ? i - 1 : 0] = 0;
    while (sfKeyboard_isKeyPressed(sfKeyBack));
    sfText_setString(map->txt[4], map->text_box);
    return (1);
}

void text_box_create(map_t *map)
{
    sfText_setPosition(map->txt[4], (sfVector2f) {505, 405});
    sfText_setString(map->txt[4], "");
    map->clock = sfClock_create();
    map->text_box = my_strcat("", "");
}

void print_box(map_t *map)
{
    static int n = 1;
    int i = 0;

    for (; map->text_box[i]; i++);
    if (!sfKeyboard_isKeyPressed(map->text_box[i - 1] - 65))
        n = 1;
    if (n) {
        n = (get_key(map)) ? 0 : n;
        if (!n)
            sfClock_restart(map->clock);
        }
    if (sfClock_getElapsedTime(map->clock).microseconds / 500000.0 > 1.0 && !n)
        n = 1;
}
