/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** update_dir
*/

#include "my_world.h"

static wd_dir_e invert_dir(wd_dir_e dir)
{
    switch (dir) {
        case SE:
            return NO;
        case NO:
            return SE;
        case NE:
            return SO;
        case SO:
            return NE;
    }
}

int update_dir(wd_game_t *game)
{
    if (game->angle_x < 45 ||  game->angle_x > 315)
        game->dir = NE;
    if (game->angle_x > 45 && game->angle_x < 135)
        game->dir = SE;
    if (game->angle_x > 135 && game->angle_x < 225)
        game->dir = SO;
    if (game->angle_x > 225 && game->angle_x < 315)
        game->dir = NO;
    if (game->angle_y > 180)
        game->dir = invert_dir(game->dir);
    return 0;
}
