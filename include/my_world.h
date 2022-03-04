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

    typedef enum wd_spritetype {
        GRASS,
        SWAMP,
        ICE,
        FIRE
    } wd_spritetype_e;

    static char *wd_spritefile[] = {
            "assets/BasicGreen.png",
            "assets/Swampset.png",
            "assets/IceSet.png",
            "assets/FireSet.png"
    };

    static int map[MAP_X][MAP_Y] = {
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 01, 00, 00},
        {00, 00, 00, 00, 00, 00},
        {00, 00, 00, 00, 00, 00},
    };

    static int map_text[MAP_X - 1][MAP_Y - 1] = {
            {04, 01, 01, 02, 01},
            {01, 01, 02, 01, 01},
            {01, 02, 04, 01, 04},
            {02, 01, 01, 03, 03},
            {01, 01, 04, 03, 03},
    };

    static sfVector2f wd_texCoords[] = {
            (sfVector2f) {.x = 0, .y = 0},
            (sfVector2f) {.x = 16, .y = 0},
            (sfVector2f) {.x = 16, .y = 16},
            (sfVector2f) {.x = 0, .y = 16}
    };

    typedef struct framebuffer_s {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
        sfTexture *texture;
        sfSprite *sprite;
    } framebuffer_t;

    typedef struct wd_map_s {
        int **map;
        int map_height;
        int map_width;
    } wd_map_t;

    typedef struct wd_game_s {
        int **map;
        int map_height;
        int map_width;
        int angle_x;
        int angle_y;
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
    sfVertexArray *create_line(sfVector2f *point1, sfVector2f* point2);
    sfRenderStates *init_text_state(wd_spritetype_e type);
    sfVector2f pos_3d_to_2d(int x, int y, int z, wd_game_t *game);
    int draw_spritemap(wd_game_t *game);
    void framebuffer_destroy(framebuffer_t *framebuffer);

#endif //MY_WORLD_H
