/*
** EPITECH PROJECT, 2022
** my_worldtest
** File description:
** change_view
*/

#include "my_world.h"

void change_zoom(wd_game_t *game, sfEvent event)
{
    switch (event.key.code) {
        case sfKeyA:
            game->map->fov += 1;
            break;
        case sfKeyE:
            game->map->fov -= 1;
            break;
        default:
            return;
    }
    update_proj_matrix(game);
}

void change_angle(wd_game_t *game, sfEvent event)
{
    switch (event.key.code) {
        default:
            return;
        case sfKeyQ:
            game->angle.x -= 4;
            FALL_THROUGH;
        case sfKeyD:
            game->angle.x += 2;
            rotate_matrix_x(game, game->angle.x);
            break;
        case sfKeyZ:
            game->angle.y += 4;
            FALL_THROUGH;
        case sfKeyS:
            game->angle.y -= 2;
            rotate_matrix_y(game, game->angle.y);
    }
    calc_end_matrix(game);
    normalize_angle(game);
}
