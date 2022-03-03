/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** print_map
*/

#include "my_world.h"

int render_map(wd_game_t*game)
{
    clean_framebuffer(game->fb);
    sfTexture_updateFromPixels(game->fb->texture, game->fb->pixels, WIDTH,
                               HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(game->win, game->fb->sprite, NULL);
    draw_lines(game);
    sfRenderWindow_display(game->win);
    return 0;
}
