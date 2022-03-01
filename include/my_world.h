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

    typedef struct framebuffer_s {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
        sfTexture *texture;
        sfSprite *sprite;
    } framebuffer_t;

    typedef struct wd_game_s {
        int angle_x;
        int angle_y;
        int **map;
        int map_height;
        int map_width;
        framebuffer_t *fb;
        sfRenderWindow *win;
    } wd_game_t;

    int check_env(char **env);
    int print_help(void);
    sfRenderWindow *render_window(void);
    int gameloop(wd_game_t *game);
    int render_map(wd_game_t *game);
    void *my_memset(int size, char *str);
    framebuffer_t *clean_framebuffer(framebuffer_t *fb);
    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void framebuffer_destroy(framebuffer_t *framebuffer);
    void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
    wd_game_t *init_game(void);
    int render_map(wd_game_t*game);

#endif //MY_WORLD_H
