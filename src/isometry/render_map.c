/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** print_map
*/

#include "my_world.h"

int draw_map(wd_game_t *game)
{
    sfVertexArray *vertexarr = sfVertexArray_create();
    sfCircleShape *circle = init_circle(50 / (game->map->fov / 10));
    int x = 0;
    int y = 0;

    sfVertexArray_setPrimitiveType(vertexarr, sfQuads);
    for (int i = 0; i < (MAP_X) * (MAP_Y); ++i) {
        x = update_x(i, game, MAP_X, MAP_Y);
        y = update_y(i, game, MAP_X, MAP_Y);
        if (sfKeyboard_isKeyPressed(sfKeyH))
            my_usleep(0.1 * 1000000);
        draw_line(game, game->map->points, y, x);
        if (x != MAP_X - 1 && y != MAP_Y - 1)
            draw_spritetile(game, x, y, vertexarr);
        circleshape_draw(game, circle, x, y);
        if (sfKeyboard_isKeyPressed(sfKeyH))
        sfRenderWindow_display(game->win);
    }
    sfCircleShape_destroy(circle);
    return 0;
}

int render_map(wd_game_t*game)
{
    //sfRenderWindow_clear(game->win, sfBlack);
    for (int y = 0; y < MAP_X; ++y)
        for (int x = 0; x < MAP_Y; ++x)
            game->map->points[x][y] = pos_3d_to_2d(x, y, map[x][y], game);
    draw_map(game);
    return 0;
}
