/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include "hud.h"

void analyse_events(wd_game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        return on_click(game, event);
    //hud_event_mouse(game->hud, &event);
}

int gameloop(hud_button_t *button __attribute__((unused)), wd_game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->win)) {
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            analyse_events(game, event);
        }
        render_map(game);
        hud_render(game->hud);
        sfRenderWindow_display(game->win);
    }
    free_game(game);
    return 0;
}

int my_world(void)
{
    wd_game_t *game = init_game();
    hud_t *menu = NULL;
    sfEvent event;

    if (game == NULL)
        return 84;
    //menu = init_menu(game->win, game);
    while (sfRenderWindow_isOpen(game->win)) {
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            //hud_event_mouse(menu, &event);
            analyse_events(game, event);
        }
        render_map(game);
        //hud_render(menu);
        sfRenderWindow_display(game->win);
    }
    return 0;
}
