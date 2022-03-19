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
    sfVector2f mouse = {(float)sfMouse_getPositionRenderWindow(game->win).x,
                        (float)sfMouse_getPositionRenderWindow(game->win).y};

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

void analyse_events(wd_game_t *game, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->win);
    if (event.type == sfEvtKeyPressed)
        return on_click(game, event);
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
    while (sfRenderWindow_isOpen(game->win)) {
        update_status(game);
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            analyse_events(game, event);
        }
        render_map(game);
        sfRenderWindow_display(game->win);
    }
    return 0;
}
