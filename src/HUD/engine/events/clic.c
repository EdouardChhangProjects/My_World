/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** clic
*/

#include "hud.h"

void hud_event_button_click(hud_button_t *button, sfEvent *event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (button->toggleable == true)
            button->toggle = (!(button->toggle));
        if (button->action != NULL && button->action->function != NULL) {
            button->action->function(button, button->action->param);
        }
    }
    /* ((hud_button_t *)buttons->data)->action->function(((hud_button_t *)
    buttons->data), ((hud_button_t *)buttons->data)->action->param); */
}

void hud_event_analyze_mouse_input(hud_t *hud, sfEvent *event,
sfVector2i mouse_pos, sfVector2i offset)
{
    for (list_t *buttons = hud->buttons; buttons != NULL;
        buttons = buttons->next) {
        if (sfIntRect_contains(&((hud_button_t *)buttons->data)->pos,
            mouse_pos.x + offset.x, mouse_pos.y + offset.y) == sfTrue) {
            ((hud_button_t *)buttons->data)->hover = true;
            hud_event_button_click(((hud_button_t *)buttons->data), event);
        } else
            ((hud_button_t *)buttons->data)->hover = false;
    }
}

void hud_event_mouse(hud_t *hud, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(hud->win);

    hud_event_analyze_mouse_input(hud, event, mouse_pos,
    (sfVector2i){.x = 0, .y = 0});
}