/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"

void huds_render(wd_game_t *game)
{
    if (game->menus.main == true)
        hud_render(game->menus.main_hud);
    if (game->menus.pause == true)
        hud_render(game->menus.pause_hud);
    if (game->menus.save == true)
        hud_render(game->menus.save_hud);
}

int gameloop(wd_game_t *game)
{
    sfEvent event;

        sfRenderWindow_clear(game->win, sfBlack);
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            analyse_win_events(game, event);
            if (huds_events(game, event) != 0)
                continue;
            if (game->status == 1) {
                analyse_events(game, event);
            }
        }
        if (game->status) {
            render_map(game);
            hud_render(game->hud);
        }
        huds_render(game);
        sfRenderWindow_display(game->win);
    return 0;
}

int my_world(void)
{
    wd_game_t *game = init_game();
    hud_t *menu = NULL;
    sfEvent event;

    if (game == NULL)
        return 84;
    if ((game = init_huds(game)) == NULL)
        return 84;
    game->status = 0;
    while (sfRenderWindow_isOpen(game->win)) {
        gameloop(game);
    }
    free_game(game);
    return 0;
}
