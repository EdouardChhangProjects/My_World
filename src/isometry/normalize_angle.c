/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** normalize_angle
*/

#include "my_world.h"

int normalize_angle(wd_game_t *game)
{
    if (game->angle_x > 360)
        game->angle_x -= 360;
    if (game->angle_x < 0)
        game->angle_x += 360;
    if (game->angle_y > 360)
        game->angle_y -= 360;
    if (game->angle_y < 0)
        game->angle_y += 360;
    return 0;
}
