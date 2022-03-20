/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** pos_3d_to_2d
*/

#include "my_world.h"

double to_radiant(double angle)
{
    return (double)(angle * M_PI / 180);
}

sfVector2f pos_3d_to_2d(int x, int y, int z, wd_game_t *game)
{
    sfVector2f vector = {0};
    sfVector3f origin = {.x = (float)x - (game->map->width / 2.0),
    .y = (float)y - (game->map->height / 2.0), .z = (float)z};

    if (x < 0 || x >= MAP_X || y < 0 || y >= MAP_Y)
        return (sfVector2f){.x = -1, .y = -1};
    origin = apply_matrix(origin, game->matrix.end_matrix);
    origin.z += 5;
    origin = apply_matrix(origin, game->matrix.proj_matrix);
    if (origin.z != 0) {
        vector.x /= origin.z;
        vector.y /= origin.z;
    }
    vector.x = origin.x * 256 + WIDTH / 2;
    vector.y = origin.y * 256 + HEIGHT / 2;
    return vector;
}
