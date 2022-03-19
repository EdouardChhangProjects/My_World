/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** circleshape_contains
*/

#include "my_world.h"

int circleshape_contains(sfCircleShape *circle, sfVector2i dot)
{
    sfVector2f pos = sfCircleShape_getPosition(circle);

    if ((dot.x - pos.x) * (dot.x - pos.x) + (dot.y - pos.y) * (dot.y - pos.y) \
        <= sfCircleShape_getRadius(circle) * sfCircleShape_getRadius(circle))
        return 1;
    return 0;
}

int circleshape_draw(wd_game_t *game, sfCircleShape *circle, int x, int y)
{
    sfCircleShape_setPosition(circle, game->map->points[x][y]);
    if (game->map->selected.x == x && game->map->selected.y == y)
        sfCircleShape_setFillColor(circle, sfRed);
    sfRenderWindow_drawCircleShape(game->win, circle, NULL);
    if (game->map->selected.x == x && game->map->selected.y == y)
        sfCircleShape_setFillColor(circle, sfWhite);
}
