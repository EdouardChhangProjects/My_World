/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"

void on_click(wd_game_t *game, sfEvent event)
{
    switch (event.key.code) {
        case sfKeyEscape:
            sfRenderWindow_close(game->win);
        default:
            return;
        case sfKeyQ:
            game->angle_x -= 4;
        case sfKeyD:
            game->angle_x += 2;
            rotate_matrix_x(game, game->angle_x);
            break;
        case sfKeyZ:
            game->angle_y += 4;
        case sfKeyS:
            game->angle_y -= 2;
            rotate_matrix_y(game, game->angle_y);
    }
    calc_end_matrix(game);
    normalize_angle(game);
}

void analyse_events(wd_game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        return on_click(game, event);
}

int gameloop(wd_game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->win)) {
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            analyse_events(game, event);
        }
        render_map(game);
    }
    free_game(game);
    return 0;
}

int my_world(void)
{
    wd_game_t *game = init_game();

    if (game == NULL)
        return 84;
    return gameloop(game);
}
