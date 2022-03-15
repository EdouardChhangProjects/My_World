/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** pos
*/

#include "hud.h"
#include <SFML/Graphics.h>

void hud_button_set_pos(hud_button_t *button, int x, int y)
{
    button->pos.left = x;
    button->pos.top = y;
    return button;
}

void hud_button_set_size(hud_button_t *button, int x, int y)
{
    button->pos.width = x;
    button->pos.height = y;
    return button;
}