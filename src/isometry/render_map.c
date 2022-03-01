/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** print_map
*/

#include "my_world.h"

double to_radiant(double angle)
{
    return (double)(angle * M_PI / 180);
}

framebuffer_t *print_point(int x, int y, int z, wd_game_t *game)
{
    x = x * 64;
    y = y * 64;
    int point_x = cos(to_radiant(game->angle_x)) * x - cos(to_radiant
            (game->angle_x)) * y;
    int point_y = sin(to_radiant(game->angle_y)) * y + sin(to_radiant
            (game->angle_y)) * x - z;
    point_x += WIDTH / 2;
    point_y += HEIGHT / 4;
    if (point_x > 0 && point_x < game->fb->width && point_y > 0 && point_y <
    game->fb->height) {
        my_put_pixel(game->fb, point_x, point_y, sfWhite);
    }
}

int render_map(wd_game_t*game)
{
    clean_framebuffer(game->fb);
    for (int y = 0; y <= 6; ++y) {
        for (int x = 0; x <= 6; ++x) {
            print_point(x, y, map[x][y], game);
        }
    }
    sfTexture_updateFromPixels(game->fb->texture, game->fb->pixels, WIDTH,
                               HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(game->win, game->fb->sprite, NULL);
    sfRenderWindow_display(game->win);
    return 0;
}
