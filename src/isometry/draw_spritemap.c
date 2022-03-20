/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** draw_spritemap
*/

#include "my_world.h"

int draw_spritetile(wd_game_t *game, unsigned int x, unsigned int y,
sfVertexArray *vertex_array)
{
    sfRenderStates *states = NULL;
    sfVertex vertex = {0};
    int tmpx = 0;
    int tmpy = 0;

    states = init_text_state(game->map->map_text[x][y]);
    sfVertexArray_clear(vertex_array);
    for (unsigned int i = 0; i < 4; ++i) {
        tmpx = ((i % 2) ^ (i >> 1));
        tmpy = (i >> 1);
        vertex.texCoords = (sfVector2f){.x = tmpx * 16, .y = tmpy * 16};
        vertex.position = pos_3d_to_2d(tmpx + x, tmpy + y,
                        game->map->map[tmpx][tmpy], game);
        vertex.color = sfWhite;
        sfVertexArray_append(vertex_array, vertex);
    }
    sfRenderWindow_drawVertexArray(game->win, vertex_array, states);
    free_states(states);
    return 0;
}

int update_x(int i, wd_game_t *game, int width, int height)
{
    int x = 0;

    switch (game->dir) {
        case SO:
            x = i % (height);
            break;
        case SE:
            x = i / (width);
            break;
        case NE:
            x = (height - 1) - (i % (height));
            break;
        case NO:
            x = (height - 1) - (i / (width));
    }
    return x;
}

int update_y(int i, wd_game_t *game, int width, int height)
{
    int y = 0;

    switch (game->dir) {
        case SO:
            y = (width - 1) - (i / (height));
            break;
        case SE:
            y = i % (width);
            break;
        case NE:
            y = i / (height);
            break;
        case NO:
            y = (width - 1) - (i % (width));
    }
    return y;
}

int draw_spritemap(wd_game_t *game)
{
    sfVertexArray *vertexarr = sfVertexArray_create();
    int x = 0;
    int y = 0;

    if (vertexarr == NULL)
        return 84;
    sfVertexArray_setPrimitiveType(vertexarr, sfQuads);
    for (int i = 0; i < (game->map->width - 1) * (game->map->height -1); i++) {
        x = update_x(i, game, MAP_X - 1, MAP_Y - 1);
        y = update_y(i, game, MAP_X - 1, MAP_Y - 1);
        draw_spritetile(game, x, y, vertexarr);
    }
    sfVertexArray_destroy(vertexarr);
    return 0;
}
