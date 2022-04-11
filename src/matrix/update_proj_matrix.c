/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** update_proj_matrix
*/

#include "my_world.h"

void update_proj_matrix(wd_game_t *game)
{
    game->matrix.proj_matrix[0][0] = SCREEN_RATIO * FOVRAD(game->map->fov);
    game->matrix.proj_matrix[1][1] = FOVRAD(game->map->fov);
    game->matrix.proj_matrix[2][2] = FFAR * (FFAR - FNEAR);
    game->matrix.proj_matrix[3][2] = (-FFAR * FNEAR) / (FFAR - FNEAR);
    game->matrix.proj_matrix[2][3] = 1;
    game->matrix.proj_matrix[3][3] = 0;
}
