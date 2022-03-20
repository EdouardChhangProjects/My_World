/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** tools
*/

#include "my_world.h"

void select_level_tool(hud_button_t *button __attribute__((unused)),
void *param)
{
    wd_game_t *game = (wd_game_t *)param;

    game->map->type = LEVEL;
}

void select_uniform_tool(hud_button_t *button __attribute__((unused)),
void *param)
{
    wd_game_t *game = (wd_game_t *)param;

    game->map->type = UNIFORM;
}
