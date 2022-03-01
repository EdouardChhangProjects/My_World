/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "my_world.h"


void analyse_events(wd_game_t *game, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game->win);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        game->angle_x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game->angle_x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        game->angle_y += 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game->angle_y -= 1;
}


int gameloop(wd_game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->win)) {
        while (sfRenderWindow_pollEvent(game->win, &event)) {
            analyse_events(game, event);
        }
        render_map(game);
    }
    sfRenderWindow_destroy(game->win);
    framebuffer_destroy(game->fb);
    return 0;
}

int my_world(void)
{
    wd_game_t *game = init_game();

    if (game == NULL)
        return 84;
    return gameloop(game);
}
