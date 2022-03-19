/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** actions
*/

#include <stddef.h>
#include <stdbool.h>
#include "my_world.h"

#ifndef ACTIONS_H_
    #define ACTIONS_H_

void test_button_press(hud_button_t *button, void *param);
void launch_game(hud_button_t *button __attribute__((unused)), void *param);
void launch_menu(hud_button_t *button __attribute__((unused)), void *param);
void exit_game(hud_button_t *button __attribute__((unused)), void *param);
void toogle_pause(hud_button_t *button __attribute__((unused)), void *param);

#endif