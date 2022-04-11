/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** textures
*/

#include "my_world.h"

void select_set_tool_grass(hud_button_t *button __attribute__((unused)),
void *param)
{
    wd_game_t *game = (wd_game_t *)param;

    game->map->type = SKIN;
    game->map->spritetype = GRASS;
}

void select_set_tool_swamp(hud_button_t *button __attribute__((unused)),
void *param)
{
    wd_game_t *game = (wd_game_t *)param;
    
    game->map->type = SKIN;
    game->map->spritetype = SWAMP;
}

void select_set_tool_ice(hud_button_t *button __attribute__((unused)),
void *param)
{
    wd_game_t *game = (wd_game_t *)param;
    
    game->map->type = SKIN;
    game->map->spritetype = ICE;
}

void select_set_tool_fire(hud_button_t *button __attribute__((unused)),
void *param)
{
    wd_game_t *game = (wd_game_t *)param;
    
    game->map->type = SKIN;
    game->map->spritetype = FIRE;
}
