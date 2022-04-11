/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** rotate_matrix
*/

#include "my_world.h"

void rotate_matrix_x(wd_game_t *game, double angle_x)
{
    game->matrix.rotx_matrix[0][0] = (float)cos(to_radiant(angle_x));
    game->matrix.rotx_matrix[0][1] = (float)sin(to_radiant(angle_x));
    game->matrix.rotx_matrix[1][0] = (float)-sin(to_radiant(angle_x));
    game->matrix.rotx_matrix[1][1] = (float)cos(to_radiant(angle_x));
    game->matrix.rotx_matrix[2][2] = 1;
    game->matrix.rotx_matrix[3][3] = 1;
}

void rotate_matrix_y(wd_game_t *game, double angle_y)
{
    angle_y *= 0.5;
    game->matrix.roty_matrix[0][0] = 1;
    game->matrix.roty_matrix[1][1] = (float)cos(to_radiant(angle_y));
    game->matrix.roty_matrix[1][2] = (float)sin(to_radiant(angle_y));
    game->matrix.roty_matrix[2][1] = (float)-sin(to_radiant(angle_y));
    game->matrix.roty_matrix[2][2] = (float)cos(to_radiant(angle_y));
    game->matrix.roty_matrix[3][3] = 1;
}
