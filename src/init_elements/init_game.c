/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_game
*/

#include "my_world.h"

void init_default_map(wd_game_t *game)
{
    game->map->map = my_memset(sizeof(int *) * (MAP_X + 1), NULL);
    for (int i = 0; i < MAP_X; i++) {
        game->map->map[i] = my_memset(sizeof(int) * (MAP_Y + 1), NULL);
        for (int j = 0; j < MAP_Y; j++)
            game->map->map[i][j] = 0;
    }
    game->map->map_text = my_memset(sizeof(int *) * (MAP_X), NULL);
    for (int i = 0; i < MAP_X - 1; i++) {
        game->map->map_text[i] = my_memset(sizeof(int) * (MAP_Y), NULL);
        for (int j = 0; j < MAP_Y - 1; j++)
            game->map->map_text[i][j] = 3;
    }
    game->map->width = MAP_X;
    game->map->height = MAP_Y;
}

wd_game_t *init_map(char **av, int ac, wd_game_t *game)
{
    game->map = my_memset(sizeof(wd_map_t), NULL);

    if (ac == 2) {
        if ((game = parse_map(game, av[1])) == NULL)
            return NULL;
    } else
        init_default_map(game);
    game->map->fov = (game->map->width * game->map->height) * 2;
    game->map->points = my_memset(sizeof(sfVector2f *) *
            (game->map->width + 1), NULL);
    for (int i = 0; i < game->map->width; ++i)
        game->map->points[i] = my_memset(sizeof(sfVector2f) *
                (game->map->height + 1), NULL);
    game->map->selected = (sfVector2i){.x = -1, .y = -1};
    return game;
}

wd_game_t *init_game(char **av, int ac)
{
    wd_game_t *game = my_memset(sizeof(wd_game_t), NULL);

    if (game == NULL)
        return NULL;
    if ((game->win = render_window()) == NULL)
        return NULL;
    if ((game = init_map(av, ac, game)) == NULL)
        return NULL;
    game->angle = (wd_vector2d_t){.x = 250, .y = 100};
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
