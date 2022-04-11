/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** draw_points
*/

#include "my_world.h"

int draw_points(wd_game_t *game)
{
    sfCircleShape *circle = init_circle(50 - (game->map->fov / 10));
    int x = 0;
    int y = 0;

    for (int i = 0; i < game->map->width * game->map->height; ++i) {
        x = i % game->map->width;
        y = i / game->map->height;
        circleshape_draw(game, circle, x, y);
    }
    sfCircleShape_destroy(circle);
    return 0;
}
