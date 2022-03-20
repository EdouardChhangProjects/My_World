/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** normalize_angle
*/

#include "my_world.h"

int normalize_angle(wd_game_t *game)
{
    if (game->angle.x > 360)
        game->angle.x -= 360;
    if (game->angle.x < 0)
        game->angle.x += 360;
    if (game->angle.y > 360)
        game->angle.y = 360;
    if (game->angle.y < 0)
        game->angle.y = 0;
    return 0;
}
