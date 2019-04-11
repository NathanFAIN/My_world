/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"

int usages(int ac, char **av)
{
    if (ac != 2 || av[1][0] != '-' || av[1][1] != 'h' || av[1][2])
        return (0);
    write(1, "2D isometric world with terraforming options\n\n", 46);
    write(1, "\033[1mUSAGES\033[0m\n\t./my_world [-h]\n\n\033[1mOPTION", 43);
    write(1, "\n\t-h  \033[0mdisplay this help and quit\n", 37);
    write(1, "\033[1mKeyboard\033[0m\n\tTranslation: 'Z' 'Q' 'S' 'D'\n", 47);
    write(1, "\tRotation: 'UP' 'DOWN' 'LEFT' 'RIGHT'\n", 38);
    write(1, "\tZoom: 'PAGE-UP' 'PAGE-DOWN' or '+' '-'\n", 40);

    return (1);
}

int main(int ac, char **av)
{
    map_t *map;

    if (usages(ac, av))
        return (0);
    if (ac > 1)
        return (84);
    map = create_map(my_menu());
    while (sfRenderWindow_isOpen(map->window)) {
        my_draw_window(map);
        draw_2d_map_face(map);
        draw_button(map);
        my_test_help(map);
        set_mouse(map);
        custom_world(map);
    }
    my_destroy(map);
    return (0);
}
