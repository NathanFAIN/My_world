/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <time.h>
#include <math.h>
#include "struct.h"

#ifndef MY_H_
#define MY_H_

int my_strlen(char *str);
void my_test_help(map_t *m);
void create_help(map_t *map);
void set_color(map_t *map, int x, int y);
float **load(char *file);
void save(float **map, char *file);
void print_box(map_t *map);
void draw_face3(map_t *map, sfVector3f p[]);
void draw_face22(map_t *map, sfVector3f p[]);
sfVector3f get_vect(float x1, float y1, map_t *map);
sfVector3f intersection_point(map_t *map, sfVector3f p1, sfVector3f p2);
void draw_face1(int i, int j, map_t *map, sfVector3f p[]);
void manage_water_printing(int i, int j, map_t *map);
void text_box_create(map_t *map);
char *my_strcat(char *str1, char *str2);
char *nbr_str(long nb);
void create_text(map_t *map);
void resize_menu(map_t *map);
map_t *my_menu(void);
void draw_resize_pen(map_t *map);
map_t *create_resize_pen(map_t *map);
void update_color(map_t *map, int x, int y, float n);
void set_smooth(map_t *map, int n);
void custom_world(map_t *map);
void set_side_map(map_t *map);
void set_map_click(map_t *map);
obj_t *create_obj(const char *fd1, const char *fd2, const char *fd3, \
sfVector2f pos);
void draw_button(map_t *map);
map_t *create_button(map_t *map);
map_t *create_map(map_t *map);
sfVector2f  project_vertex(float x, float y, float z, map_t *map);
sfVector2f **project_terrain(map_t *map);
float perlin2d(float x, float y, float freq, int depth);
sfVector2f project_iso_point(float x, float y, float z, map_t *map);
void create_2d_color(map_t *map);
void create_3d_map(map_t *map, float freq, float eq);
int **create_map3d(void);
void create_2d_map(map_t *map);
sfRenderWindow *create_window(void);
void my_draw_window(map_t *map);
void draw_face(int x, int y, map_t *map);
void draw_2d_map_face(map_t *map);
sfVector2f **update_rotate(map_t *map);
void my_destroy(map_t *map);
void set_mouse(map_t *map);
sfVector2f my_custom(map_t *map);
void update_2d_map(map_t *map, float n, int len);

#endif /* MY_H_ */

#define SEED   2
#define SIZE_X   1800
#define SIZE_Y   1000
#define MAP_X   150
#define MAP_Y   150
