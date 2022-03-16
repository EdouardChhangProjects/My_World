/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_game
*/

#include "my_world.h"

wd_game_t *init_game(void)
{
    wd_game_t *game = my_memset(sizeof(wd_game_t), NULL);

    if (game == NULL)
        return NULL;
    game->fb = framebuffer_create(WIDTH, HEIGHT);
    game->win = render_window();
    game->angle_x = 35;
    game->angle_y = 45;
    game->map = (int **)map;
    game->map_width = MAP_X;
    game->map_height = MAP_Y;
    game->matrix.base_matrix = init_matrix(0);
    game->matrix.rotx_matrix = init_matrix(1);
    game->matrix.roty_matrix = init_matrix(1);
    rotate_matrix_x(game, game->angle_x);
    rotate_matrix_y(game, game->angle_y);
    game->matrix.proj_matrix = init_proj_matrix();
    game->matrix.end_matrix = init_matrix(1);
    calc_end_matrix(game);
    return game;
}
