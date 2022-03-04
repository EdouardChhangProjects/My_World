/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** points
*/

#include "my_world.h"

sfVector2f *get_point(int x, int y, int z, wd_game_t *game)
{
    sfVector2f *point = malloc(sizeof(sfVector2f));

    x *= 64;
    y *= 64;
    z *= 64;
    point->x = cos(to_radiant(game->angle_x)) * x - cos(to_radiant
            (game->angle_x)) * y;
    point->y = sin(to_radiant(game->angle_y)) * y + sin(to_radiant
            (game->angle_y)) * x - z;
    point->x += WIDTH / 2;
    point->y += HEIGHT / 4;
    if (point->x > 0 && point->x < game->fb->width && point->y > 0 && point->y <
    game->fb->height) {
        return point;
    }
    point->x = -1;
    point->y = -1;
    return point;
}

sfVector2f ***get_points(wd_game_t *game)
{
    int X = 6;
    int Y = 6;
    sfVector2f ***points = malloc(sizeof(sfVector2f **) * (Y + 1));

    for (int y = 0; y < Y; ++y) {
        points[y] = malloc(sizeof(sfVector2f *) * (X + 1));
        for (int x = 0; x < X; ++x) {
            points[y][x] = malloc(sizeof(sfVector2f) * 1);
        }
        points[y][X] = NULL;
    }
    for (int y = 0; y < Y; ++y)
        for (int x = 0; x < X; ++x)
            *(points[y][x]) = pos_3d_to_2d(x, y, map[x][y], game);
    points[Y] = NULL;
    return points;
}
