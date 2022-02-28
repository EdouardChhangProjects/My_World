/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/


#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>
#include <time.h>
#include "list.h"
#include "my.h"
#include "printerr.h"
#include "printf.h"
#include "math.h"

#ifndef MY_WORLD_H
    #define MY_WORLD_H

    #include <stdlib.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window/Mouse.h>
    #include <time.h>

    #define HELP "assets/help.txt"

    #define WIDTH 1920
    #define HEIGHT 1080
    #define FPS 80
    #define MAP_X 6
    #define MAP_Y 6

    static int map[MAP_X][MAP_Y] = {
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
    };

    struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
        sfTexture *texture;
        sfSprite *sprite;
    };

    typedef struct framebuffer framebuffer_t;

    int check_env(char **env);
    int print_help(void);
    sfRenderWindow *render_window(void);
    int gameloop(void);
    int render_map(sfRenderWindow* win, framebuffer_t *fb, double angle_x,
                   double angle_y);
    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void *my_memset(int size, char *str);

#endif //MY_WORLD_H
