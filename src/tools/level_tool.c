/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** level_tool
*/

#include "my_world.h"

void level_tool(wd_game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);

    if (game->map->selected.x != -1) {
        if (pos_3d_to_2d(game->map->selected.x, game->map->selected.y,
            SELECTED_TILE + 1, game).y > (float)mouse.y)
            SELECTED_TILE += 1;
        if (pos_3d_to_2d(game->map->selected.x, game->map->selected.y,
            SELECTED_TILE - 1, game).y < (float)mouse.y)
            SELECTED_TILE -= 1;
    }
}

void union_tool(wd_game_t *game)
{
    sfVector2f dot = {-1, -1};
    sfCircleShape *circle = init_circle(500 / (game->map->fov / 10));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);
    int tmpx = 0;
    int tmpy = 0;

    for (int i = 0; i < 4; i++) {
        tmpx = (game->map->selected.x) + (i - 1) * (i % 2 == 0);
        tmpy = (game->map->selected.y) + (i - 2) * (i % 2 == 1);
        if (game->map->selected.x != -1)
            dot = pos_3d_to_2d(tmpx, tmpy, SELECTED_TILE, game);
        if (dot.x == -1)
            continue;
        sfCircleShape_setPosition(circle, dot);
        if (circleshape_contains(circle, mouse)) {
            game->map->map[tmpx][tmpy] = SELECTED_TILE;
            game->map->selected = (sfVector2i){.x = tmpx, .y = tmpy};
        }
    }
}

void skin_tool(wd_game_t *game)
{
    int x = 0;
    int y = 0;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);

    for (int i = 0; i < (game->map->width - 1) * (game->map->height - 1); ++i) {
        x = update_x(i, game, game->map->width - 1, game->map->height - 1);
        y = update_y(i, game, game->map->width - 1, game->map->height - 1);
        if (tile_contains(game, mouse, game->map->points[x][y])) {
            game->map->map_text[x][y] = 1;
            return;
        }
    }
}
