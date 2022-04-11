/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** button
*/

#include "hud.h"

void hub_append_button(hud_t *hud, hud_button_t *button)
{
    list_append(hud->buttons, button);
}