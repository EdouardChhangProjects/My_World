/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** draw_line
*/

#include "my_world.h"

sfVertexArray *create_line(sfVector2f point1, sfVector2f point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = point1, .color = sfWhite};
    sfVertex vertex2 = {.position = point2, .color = sfWhite};

    if (point1.x == -1 || point1.y == -1 ||
        point2.x == -1 || point2.y == -1)
        return NULL;
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int draw_line(wd_game_t *game, sfVector2f **points, int x, int y)
{
    sfVertexArray *line = NULL;

    if (y > 0) {
        line = create_line(points[y - 1][x], points[y][x]);
        if (line == NULL)
            return 1;
        sfRenderWindow_drawVertexArray(game->win, line, NULL);
        sfVertexArray_destroy(line);
    }
    if (x > 0) {
        line = create_line(points[y][x - 1], points[y][x]);
        if (line == NULL)
            return 2;
        sfRenderWindow_drawVertexArray(game->win, line, NULL);
        sfVertexArray_destroy(line);
    }
    return 0;
}

int draw_lines(wd_game_t *game)
{
    game->map->points = get_points(game);
    for (int y = 0; y < game->map->height; y++) {
        for (int x = 0; x < game->map->width; x++) {
            draw_line(game, points, x, y);
        }
    }
    return 0;
}
