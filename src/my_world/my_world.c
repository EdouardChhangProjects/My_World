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
            game->angle_x -= 2;
        case sfKeyD:
            game->angle_x += 1;
            rotate_matrix_x(game, game->angle_x);
            break;
        case sfKeyZ:
            game->angle_y += 2;
        case sfKeyS:
            game->angle_y -= 1;
            rotate_matrix_y(game, game->angle_y);
    }
    calc_end_matrix(game);
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
    sfRenderWindow_destroy(game->win);
    framebuffer_destroy(game->fb);
    return 0;
}

int my_world(void)
{
    wd_game_t *game = init_game();
    //float **matrix = init_matrix(0);

    /*matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;
    game->matrix.matrix[0][0] = 0;
    game->matrix.matrix[0][1] = 1;
    game->matrix.matrix[1][0] = 0;
    game->matrix.matrix[1][1] = 0;
    show_matrix(matrix);
    show_matrix(game->matrix.matrix);
    show_matrix(multiply_matrix(matrix, game->matrix.matrix));
    show_matrix(multiply_matrix(game->matrix.matrix, matrix));
    return 0;*/
    if (game == NULL)
        return 84;
    return gameloop(game);
}
