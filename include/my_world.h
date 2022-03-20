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
#include <math.h>
#include "hud.h"

#ifndef MY_WORLD_H
    #define MY_WORLD_H

    typedef enum wd_dir_e {
        SE,
        NO,
        NE,
        SO
    } wd_dir_t;

    typedef enum wd_type_e {
        LEVEL,
        UNIFORM,
        SKIN
    } wd_type_t;

    typedef struct wd_vector2d_s {
        double x;
        double y;
    } wd_vector2d_t;

    typedef struct framebuffer_s {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
        sfTexture *texture;
        sfSprite *sprite;
    } framebuffer_t;

    typedef struct wd_map_s {
        int **map;
        int **map_text;
        char *path;
        int height;
        int width;
        float fov;
        sfVector2f **points;
        sfVertexArray **line;
        sfVector2i selected;
        wd_type_t type;
    } wd_map_t;

    typedef struct wd_matrix4x4_s {
        float **base_matrix;
        float **rotx_matrix;
        float **roty_matrix;
        float **end_matrix;
        float **proj_matrix;
    } wd_matrix4x4_t;

    struct menus_s {
        bool main;
        hud_t *main_hud;
        bool pause;
        hud_t *pause_hud;
        bool save;
        hud_t *save_hud;
    };

    typedef struct wd_game_s {
        wd_vector2d_t angle;
        framebuffer_t *fb;
        sfRenderWindow *win;
        wd_matrix4x4_t matrix;
        struct menus_s menus;
        hud_t *hud;
        int status;
        wd_map_t *map;
        wd_dir_t dir;

    } wd_game_t;

    #if defined(__GNUC__) && __GNUC__ >= 7
        #define FALL_THROUGH __attribute__((fallthrough))
    #else
        #define FALL_THROUGH ((void)0)
    #endif

    #define HELP "assets/help.txt"

    #define WIDTH 1920
    #define HEIGHT 1080
    #define SCREEN_RATIO WIDTH / HEIGHT
    #define FPS 80
    #define MAP_X 6
    #define MAP_Y 6
    #define FNEAR 1.0
    #define FFAR 10.0
    #define FOV 45.0
    #define FOVRAD(x) (1.0 / tan((x) * 0.5 / 180.0f * M_PI))
    #define SELECTED_TILE game->map->map[game->map->selected.x]\
                                                [game->map->selected.y]

    typedef enum wd_spritetype {
        GRASS,
        SWAMP,
        ICE,
        FIRE
    } wd_spritetype_t;

    int my_world(char **av, int ac);
    int gameloop(wd_game_t *game);
    wd_game_t *init_huds(wd_game_t *game);
    void analyse_events(wd_game_t *game, sfEvent event);
    void analyse_win_events(wd_game_t *game, sfEvent event);
    int huds_events(wd_game_t *game, sfEvent event);
    char *file_to_str(char *filepath);
    int check_env(char **env);
    int print_help(void);
    sfRenderWindow *render_window(void);
    void *my_memset(int size, char *str);
    wd_game_t *init_game(char **av, int ac);
    wd_game_t *parse_map(wd_game_t *game, char *filepath);
    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void framebuffer_destroy(framebuffer_t *framebuffer);
    void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);
    int render_map(wd_game_t*game);
    sfVertexArray *create_line(sfVector2f point1, sfVector2f point2);
    sfRenderStates *init_text_state(wd_spritetype_t type);
    sfVector2f pos_3d_to_2d(int x, int y, int z, wd_game_t *game);
    int draw_spritemap(wd_game_t *game);
    double to_radiant(double angle);
    int draw_lines(wd_game_t *game);
    sfVector2f **get_points(wd_game_t *game);
    float **init_matrix(int empty);
    int show_matrix(float **matrix);
    float **multiply_matrix(float **matrix1, float **matrix2);
    sfVector3f apply_matrix(sfVector3f vector, float **matrix);
    void rotate_matrix_x(wd_game_t *game, double angle_x);
    void rotate_matrix_y(wd_game_t *game, double angle_y);
    float **init_proj_matrix(void);
    int calc_end_matrix(wd_game_t *game);
    hud_t *init_hud(wd_game_t *game);
    hud_t *init_menu(sfRenderWindow * win, wd_game_t *game);
    int free_states(sfRenderStates *states);
    int normalize_angle(wd_game_t *game);
    int free_matrix(float **matrix);
    int free_game(wd_game_t *game);
    void on_click(wd_game_t *game, sfEvent event);
    int update_dir(wd_game_t *game);
    void update_proj_matrix(wd_game_t *game);
    int draw_points(wd_game_t *game);
    sfVector2i get_selected_circle(wd_game_t *game, float radius);
    sfCircleShape *init_circle(float radius);
    int circleshape_contains(sfCircleShape *circle, sfVector2i dot);
    int circleshape_draw(wd_game_t *game, sfCircleShape *circle, int x, int y);
    int update_x(int i, wd_game_t *game, int width, int height);
    int update_y(int i, wd_game_t *game, int width, int height);
    int draw_spritetile(wd_game_t *game, unsigned int x, unsigned int y,
                    sfVertexArray *vertex_array);
    int draw_line(wd_game_t *game, sfVector2f **points, int x, int y);
    int my_usleep(long long time);
    void level_tool(wd_game_t *game);
    void union_tool(wd_game_t *game);
    int tile_contains(wd_game_t *game, sfVector2i point, sfVector2f dot);
    void change_zoom(wd_game_t *game, sfEvent event);
    void change_angle(wd_game_t *game, sfEvent event);
    void skin_tool(wd_game_t *game);
    
#endif
