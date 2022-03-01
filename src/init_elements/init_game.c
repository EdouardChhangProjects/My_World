/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_game
*/

#include "my_world.h"

wd_game_t *init_game(void)
{
    wd_game_t *game = my_memset(sizeof(wd_game_t), NULL);

    if (game == NULL)
        return NULL;
    game->fb = framebuffer_create(WIDTH, HEIGHT);
    game->win = render_window();
    game->angle_x = 35;
    game->angle_y = 45;
    game->map = (int **)map;
    game->map_width = MAP_X;
    game->map_height = MAP_Y;
    return game;
}
