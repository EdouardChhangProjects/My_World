/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** triangle_contains
*/

#include <math.h>
#include "my_world.h"

int tri_area(sfVector2f v1, sfVector2f v2, sfVector2f v3)
{
    float area = 0;

    area = v1.x * (v2.y - v3.y) +
        v2.x * (v3.y - v1.y) +
        v3.x * (v1.y - v2.y);
    area /= 2;
    return abs((int)area);
}
int tri_contains(sfVector2f v1, sfVector2f v2, sfVector2f v3, sfVector2f dot)
{
    int full_tri = tri_area(v1, v2, v3);
    int sub_tri1 = tri_area(dot, v2, v3);
    int sub_tri2 = tri_area(v1, dot, v3);
    int sub_tri3 = tri_area(v1, v2, dot);

    return (sub_tri1 + sub_tri2 + sub_tri3 <= full_tri);
}

int tile_contains(wd_game_t *game, sfVector2i point, sfVector2f dot)
{
    int tri_one = 0;
    int tri_two = 0;

    if (point.x >= game->map->height -1 || point.y >= game->map->width - 1)
        return 0;
    tri_one = tri_contains(game->map->points[point.x][point.y],
    game->map->points[point.x + 1][point.y],
    game->map->points[point.x][point.y + 1], dot);
    tri_two = tri_contains(game->map->points[point.x][point.y + 1],
    game->map->points[point.x + 1][point.y],
    game->map->points[point.x + 1][point.y + 1], dot);
    return (tri_one || tri_two);
}
