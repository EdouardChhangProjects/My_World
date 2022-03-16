/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** calc_end_matrix
*/

#include "my_world.h"

int calc_end_matrix(wd_game_t *game)
{
    float **tmpx_matrix = multiply_matrix(game->matrix.base_matrix,
                                          game->matrix.rotx_matrix);

    free_matrix(game->matrix.end_matrix);
    game->matrix.end_matrix = multiply_matrix(tmpx_matrix,
                                              game->matrix.roty_matrix);
    free_matrix(tmpx_matrix);
    return 0;
}
