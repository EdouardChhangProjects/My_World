/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_game
*/

#include "my_world.h"

wd_game_t *init_default_map(wd_game_t *game)
{
    game->map->map = malloc(sizeof(int*) * (6 + 1));
    for (int i = 0; i < 6; i++) {
        game->map->map[i] = malloc(sizeof(int) * (6 + 1));
        for (int j = 0; j < 6; j++) {
            game->map->map[i][j] = 0;
        }
    }
    game->map->map_text = malloc(sizeof(int*) * (5 + 1));
    for (int i = 0; i < 5; i++) {
        game->map->map_text[i] = malloc(sizeof(int) * (5 + 1));
        for (int j = 0; j < 5; j++) {
            game->map->map_text[i][j] = 3;
        }
    }
    game->map->width = 6;
    game->map->height = 6;
    return game;
}

wd_map_t *init_map(char **av, int ac, wd_game_t *game)
{
    game->map = my_memset(sizeof(wd_map_t), NULL);

    if (ac == 2) {
        if ((game = parse_map(game, av[1])) == NULL)
            return NULL;
    } else
        game = init_default_map(game);
    game->map->fov = (game->map->width * game->map->height);
    game->map->points = my_memset(sizeof(sfVector2f *) * (game->map->width + 1),
    NULL);
    for (int i = 0; i < game->map->width; ++i)
        game->map->points[i] = my_memset(sizeof(sfVector2f) * game->map->height,
        NULL);
    game->map->selected = (sfVector2i){.x = -1, .y = -1};
    return game;
}

wd_game_t *init_game(char **av, int ac)
{
    wd_game_t *game = my_memset(sizeof(wd_game_t), NULL);

    if (game == NULL)
        return NULL;
    game->fb = framebuffer_create(WIDTH, HEIGHT);
    if ((game->win = render_window()) == NULL)
        return NULL;
    if ((game = init_map(av, ac, game)) == NULL)
        return NULL;
    game->angle = (wd_vector2d_t){.x = 250, .y = 150};
    game->matrix.base_matrix = init_matrix(0);
    game->matrix.rotx_matrix = init_matrix(1);
    game->matrix.roty_matrix = init_matrix(1);
    rotate_matrix_x(game, game->angle.x);
    rotate_matrix_y(game, game->angle.y);
    game->matrix.proj_matrix = init_matrix(1);
    update_proj_matrix(game);
    game->matrix.end_matrix = init_matrix(1);
    calc_end_matrix(game);
    game->dir = NO;
    return game;
}

int free_game(wd_game_t *game)
{
    free_matrix(game->matrix.base_matrix);
    free_matrix(game->matrix.rotx_matrix);
    free_matrix(game->matrix.roty_matrix);
    free_matrix(game->matrix.proj_matrix);
    free_matrix(game->matrix.end_matrix);
    return 0;
}
