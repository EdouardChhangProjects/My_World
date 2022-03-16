/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** struct
*/

#include "hud.h"

hud_button_t *hud_button_init(void)
{
    hud_button_t *button = malloc(sizeof(hud_button_t));

    button->pos = (sfIntRect){.left = 0, .top = 0, .width = 100, .height = 100};
    button->border = true;
    button->borderWidth = (sfFloatRect){.left = 5, .top = 5,
    .width = 5, .height = 5};
    button->color = sfGreen;
    button->borderColor = sfRed;
    button->actionColor = sfRed;
    button->actionBorderColor = sfGreen;
    button->toggle = false;
    button->toggleable = false;
    button->hover = false;
    button->texture = NULL;
    button->hidden = false;
    return button;
}