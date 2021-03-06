/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** events
*/

#include "my_world.h"
#include "actions.h"

void on_input(wd_game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ || event.key.code == sfKeyD || \
        event.key.code == sfKeyZ || event.key.code == sfKeyS)
        change_angle(game, event);
    if (event.key.code == sfKeyA || event.key.code == sfKeyE)
        change_zoom(game, event);
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->win);
}

void analyse_events(wd_game_t *game, sfEvent event)
{
    if (hud_event_mouse(game->hud, &event) != 0)
        return;
    if (event.type == sfEvtKeyPressed)
        on_input(game, event);
}

void analyse_win_events(wd_game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->win);
}

int huds_events(wd_game_t *game, sfEvent event)
{
    if (game->menus.main == true)
        if (hud_event_mouse(game->menus.main_hud, &event) != 0)
            return 1;
    if (game->menus.pause == true)
        if (hud_event_mouse(game->menus.pause_hud, &event) != 0)
            return 2;
    if (game->menus.save == true)
        if (hud_event_mouse(game->menus.save_hud, &event) != 0)
            return 3;
    return 0;
}
