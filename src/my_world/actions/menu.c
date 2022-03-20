/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** menu
*/

#include "my_world.h"

void launch_game(hud_button_t *button __attribute__((unused)), void *param)
{
    wd_game_t *game = (wd_game_t*)param;

    game->menus.main = false;
    game->menus.pause = false;
    game->menus.save = false;
    game->status = 1;
}

void launch_menu(hud_button_t *button __attribute__((unused)), void *param)
{
    wd_game_t *game = (wd_game_t*)param;

    game->menus.main = true;
    game->menus.pause = false;
    game->menus.save = false;
    game->status = 0;
}

void exit_game(hud_button_t *button __attribute__((unused)), void *param)
{
    wd_game_t *game = (wd_game_t*)param;

    sfRenderWindow_close(game->win);
    game->status = 0;
}

void toogle_pause(hud_button_t *button __attribute__((unused)), void *param)
{
    wd_game_t *game = (wd_game_t*)param;

    game->menus.main = false;
    game->menus.save = false;
    if (game->menus.pause == true) {
        game->menus.pause = false;
        game->status = 1;
        return;
    }
    game->menus.pause = true;
    game->status = 0;
}
