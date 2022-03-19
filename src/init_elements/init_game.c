/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_game
*/

#include "my_world.h"

wd_map_t *init_map(void)
{
    wd_map_t *dest = my_memset(sizeof(wd_map_t), NULL);

    dest->map = (int **)map;
    dest->width = MAP_X;
    dest->height = MAP_Y;
    dest->fov = (float)(dest->width * dest->height) * 4;
    dest->type = LEVEL;
    dest->points = my_memset(sizeof(sfVector2f *) * (MAP_X + 1), NULL);
    for (int i = 0; i < MAP_X; ++i)
        dest->points[i] = my_memset(sizeof(sfVector2f) * MAP_Y, NULL);
    dest->selected = (sfVector2i){.x = -1, .y = -1};
    return dest;
}

wd_game_t *init_game(void)
{
    wd_game_t *game = my_memset(sizeof(wd_game_t), NULL);

    if (game == NULL)
        return NULL;
    game->fb = framebuffer_create(WIDTH, HEIGHT);
    game->win = render_window();
    game->map = init_map();
    game->angle = (wd_vector2d_t){.x = 250, .y = 150};
    game->matrix.base_matrix = init_matrix(0);
    game->matrix.rotx_matrix = init_matrix(1);
    game->matrix.roty_matrix = init_matrix(1);
    rotate_matrix_x(game, game->angle.x);
    rotate_matrix_y(game, game->angle.y);
    game->matrix.proj_matrix = init_matrix(1);
    update_proj_matrix(game);
    game->matrix.end_matrix = init_matrix(1);
    calc_end_matrix(game);
    game->dir = NO;
    return game;
}

int free_game(wd_game_t *game)
{
    framebuffer_destroy(game->fb);
    sfRenderWindow_destroy(game->win);
    free_matrix(game->matrix.base_matrix);
    free_matrix(game->matrix.rotx_matrix);
    free_matrix(game->matrix.roty_matrix);
    free_matrix(game->matrix.proj_matrix);
    free_matrix(game->matrix.end_matrix);
    return 0;
}
