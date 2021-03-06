/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** hud
*/

#include "my_world.h"
#include "actions.h"

hud_t *init_hud(wd_game_t *game)
{
    list_t *actions = NULL;
    hud_t *hud = NULL;

    actions = hud_action_append(actions, "level_tool", &select_level_tool,
    game);
    actions = hud_action_append(actions, "uniform_tool", &select_uniform_tool,
    game);
    actions = hud_action_append(actions, "set_tool_grass",
    &select_set_tool_grass, game);
    actions = hud_action_append(actions, "set_tool_swamp",
    &select_set_tool_swamp, game);
    actions = hud_action_append(actions, "set_tool_ice", &select_set_tool_ice,
    game);
    actions = hud_action_append(actions, "set_tool_fire", &select_set_tool_fire,
    game);
    actions = hud_action_append(actions, "toogle_pause", &toogle_pause, game);
    actions = hud_action_append(actions, "play_sound", &play_sound, NULL);
    hud = hud_init(game->win, actions, "assets/hud/hud.txt");
    return hud;
}

hud_t *init_main_hud(wd_game_t *game)
{
    list_t *actions = NULL;
    hud_t *hud = NULL;

    actions = hud_action_append(actions, "launch_game", &launch_game, game);
    actions = hud_action_append(actions, "exit_game", &exit_game, game);
    hud = hud_init(game->win, actions, "assets/hud/main.txt");
    return hud;
}

hud_t *init_pause_hud(wd_game_t *game)
{
    list_t *actions = NULL;
    hud_t *hud = NULL;

    actions = hud_action_append(actions, "toogle_pause", &toogle_pause, game);
    actions = hud_action_append(actions, "launch_menu", &launch_menu, game);
    hud = hud_init(game->win, actions, "assets/hud/pause.txt");
    return hud;
}

hud_t *init_save_hud(wd_game_t *game)
{
    list_t *actions = NULL;
    hud_t *hud = NULL;

    actions = hud_action_append(actions, "start_game", &launch_game, game);
    hud = hud_init(game->win, actions, "assets/hud/save.txt");
    return hud;
}

wd_game_t *init_huds(wd_game_t *game)
{
    game->hud = init_hud(game);
    game->menus.main = true;
    game->menus.main_hud = init_main_hud(game);
    game->menus.pause = false;
    game->menus.pause_hud = init_pause_hud(game);
    game->menus.save = false;
    game->menus.save_hud = init_save_hud(game);
    if (game->hud == NULL || game->menus.main_hud == NULL ||
        game->menus.pause_hud == NULL || game->menus.save_hud == NULL)
        return NULL;
    return game;
}