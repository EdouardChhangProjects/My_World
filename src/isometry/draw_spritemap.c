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
        tmpx = (int)(x) + ((i % 2) ^ (i >> 1));
        tmpy = (int)(y) + (i >> 1);
        vertex.texCoords = wd_texCoords[i];
        vertex.position = pos_3d_to_2d(tmpx, tmpy, game->map->map[tmpx][tmpy],
        game);
        vertex.color = sfWhite;
        sfVertexArray_append(vertex_array, vertex);
    }
    sfRenderWindow_drawVertexArray(game->win, vertex_array, states);
    free(states);
    return 0;
}

static int update_x(int i, wd_game_t *game)
{
    int x = 0;

    switch (game->dir) {
        case NE:
            x = i % (game->map->width - 1);
            break;
        case NO:
            x = i / (game->map->width - 1);
            break;
        case SO:
            x = (game->map->width - 1) - (i % (game->map->width - 1)) - 1;
            break;
        case SE:
            x = (game->map->width - 1) - (i / (game->map->width - 1)) - 1;
    }
    return x;
}

static int update_y(int i, wd_game_t *game)
{
    int y = 0;

    switch (game->dir) {
        case NE:
            y = (game->map->height - 2) - (i / (game->map->height - 1));
            break;
        case NO:
            y = i % (game->map->height - 1);
            break;
        case SO:
            y = i / (game->map->width - 1);
            break;
        case SE:
            y = (game->map->height - 1) - (i % (game->map->width - 1)) - 1;
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
        x = update_x(i, game);
        y = update_y(i, game);
        if (sfKeyboard_isKeyPressed(sfKeyH))
            usleep(10000 * 5);
        draw_spritetile(game, x, y, vertexarr);
        if (sfKeyboard_isKeyPressed(sfKeyH))
            sfRenderWindow_display(game->win);
    }
    sfVertexArray_destroy(vertexarr);
    return 0;
}
