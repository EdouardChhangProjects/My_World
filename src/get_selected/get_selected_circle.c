/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** get_selected_circle
*/

#include "my_world.h"

sfVector2i get_selected_circle(wd_game_t *game, float radius)
{
    sfVector2i dest = (sfVector2i){.x = -1, .y = -1};
    int x = 0;
    int y = 0;
    sfCircleShape *circle = init_circle(radius);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);

    for (int i = 0; i < game->map->width * game->map->height; ++i) {
        x = i % game->map->width;
        y = i / game->map->height;
        sfCircleShape_setPosition(circle, game->map->points[x][y]);
        if (circleshape_contains(circle, mouse))
            dest = (sfVector2i){.x = x, .y = y};
    }
    return dest;
}
