/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** border_size
*/

#include "hud.h"

void hud_button_set_border_size(hud_button_t *button, sfFloatRect borderWidth)
{
    button->borderWidth = borderWidth;
}