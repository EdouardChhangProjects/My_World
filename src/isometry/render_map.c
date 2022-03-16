/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** print_map
*/

#include "my_world.h"

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
        for (int x = 0; x < 6; ++x)
            print_point(x, y, map[x][y], game);
    }
    sfTexture_updateFromPixels(game->fb->texture, game->fb->pixels, WIDTH,
                               HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(game->win, game->fb->sprite, NULL);
    update_dir(game);
    draw_lines(game);
    draw_spritemap(game);
    return 0;
}
