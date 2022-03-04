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

sfVector2f pos_3d_to_2d(int x, int y, int z, wd_game_t *game)
{
    sfVector2f vector = {0};
    float tmpx = 0;
    float tmpy = 0;
    float cos_rot = cos(to_radiant(game->angle_x));
    float sin_rot = sin(to_radiant(game->angle_y));

    x *= 64;
    y *= 64;
    z *= 64;
    vector.x = cos_rot * x - cos_rot * y;
    vector.y = sin_rot * y + sin_rot * x - z;
    vector.x *= 2;
    vector.y *= 2;
    //vector.x = (game->angle_x / 20) * x + (game->angle_x / 20) * y;
    //vector.y = ((game->angle_y / 20) * y) - ((game->angle_y / 20) * x) - z;
    vector.x += WIDTH / 2;
    vector.y += HEIGHT / 4;
    return vector;
}

sfVector2f print_point(int x, int y, int z, wd_game_t *game)
{
    sfVector2f vector = pos_3d_to_2d(x, y, z, game);
    sfVector2f vector2 = pos_3d_to_2d(x, y, 0, game);

    if (vector.x > 0 && vector.x < game->fb->width && \
    vector.y > 0 && vector.y < game->fb->height) {
        my_put_pixel(game->fb, vector.x, vector.y, sfWhite);
    }
}

int render_map(wd_game_t*game)
{
    clean_framebuffer(game->fb);
    for (int y = 0; y < 6; ++y) {
        sfRenderWindow_clear(game->win, sfBlack);
        for (int x = 0; x < 6; ++x) {
            print_point(x, y, map[x][y], game);
        }
    }
    sfTexture_updateFromPixels(game->fb->texture, game->fb->pixels, WIDTH,
                               HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(game->win, game->fb->sprite, NULL);
    draw_spritemap(game);
    draw_lines(game);
    sfRenderWindow_display(game->win);
    return 0;
}
