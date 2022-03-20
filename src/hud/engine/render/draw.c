/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** draw
*/

#include "hud.h"

void hud_render_buttons(hud_t *hud)
{
    list_t *buttons = hud->buttons;

    while (buttons != NULL) {
        hud_button_render(hud->win, ((hud_button_t *)buttons->data),
        (sfVector2f){.x = 0, .y = 0});
        buttons = buttons->next;
    }
}

void hud_render(hud_t *hud)
{
    hud_render_buttons(hud);
}
