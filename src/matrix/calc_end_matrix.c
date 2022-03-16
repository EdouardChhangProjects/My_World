/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** calc_end_matrix
*/

#include "my_world.h"

int calc_end_matrix(wd_game_t *game)
{
    game->matrix.end_matrix = multiply_matrix(
            multiply_matrix(
                    game->matrix.base_matrix,
                    game->matrix.rotx_matrix
            ) , game->matrix.roty_matrix);
    return 0;
}
