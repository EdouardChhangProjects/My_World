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

    states = init_text_state(map_text[x][y]);
    sfVertexArray_clear(vertex_array);
    for (unsigned int i = 0; i < 4; ++i) {
        tmpx = (int)(x) + ((i % 2) ^ (i >> 1));
        tmpy = (int)(y) + (i >> 1);
        vertex.texCoords = wd_texCoords[i];
        vertex.position = pos_3d_to_2d(tmpx, tmpy, map[tmpx][tmpy], game);
        vertex.color = sfWhite;
        sfVertexArray_append(vertex_array, vertex);
    }
    sfRenderWindow_drawVertexArray(game->win, vertex_array, states);
    free(states);
    return 0;
}

int draw_spritemap(wd_game_t *game)
{
    sfVertexArray *vertexarr = sfVertexArray_create();

    if (vertexarr == NULL)
        return 84;
    sfVertexArray_setPrimitiveType(vertexarr, sfQuads);
    for (unsigned int x = 0; x < MAP_X - 1; ++x)
        for (unsigned int y = 0; y < MAP_Y - 1; ++y)
            draw_spritetile(game, x, y, vertexarr);
    sfVertexArray_destroy(vertexarr);
    return 0;
}
