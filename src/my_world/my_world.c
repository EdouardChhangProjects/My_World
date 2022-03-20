/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include "hud.h"

void update_status(wd_game_t *game)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        game->map->selected = get_selected_circle(game, 50 - \
        (game->map->fov / 10));
    } else {
        if (game->map->type == LEVEL)
            level_tool(game);
        if (game->map->type == UNIFORM)
            union_tool(game);
    }
    update_dir(game);
}

int gameloop(wd_game_t *game)
{
    sfEvent event;
    static int i = 0;

        update_status(game);
        sfRenderWindow_clear(game->win, sfBlack);
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            analyse_win_events(game, event);
            if (huds_events(game, event) != 0)
                continue;
            if (game->status == 1) {
                analyse_events(game, event);
            }
        }
        if (game->status == 1) {
            render_map(game);
            hud_render(game->hud);
        }
    }
    if (game->status) {
        render_map(game);
        hud_render(game->hud);
    }
    sfRenderWindow_display(game->win);
    return 0;
}

int my_world(char **av, int ac)
{
    wd_game_t *game = init_game(av, ac);
    sfEvent event;

    if (game == NULL)
        return 84;
    if ((game = init_huds(game)) == NULL)
        return 84;
    game->status = 0;
    while (sfRenderWindow_isOpen(game->win))
        gameloop(game);
    free_game(game);
    return 0;
}
