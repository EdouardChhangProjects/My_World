/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** clic
*/

#include "hud.h"

int hud_event_button_click(hud_button_t *button, sfEvent *event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (button->toggleable == true)
            button->toggle = (!(button->toggle));
        if (button->action != NULL && button->action->function != NULL) {
            button->action->function(button, button->action->param);
        }
        return 1;
    }
    return 2;
}

int hud_event_analyze_mouse_input(hud_t *hud, sfEvent *event,
sfVector2i mouse_pos, sfVector2i offset)
{
    int used = 0;

    for (list_t *buttons = hud->buttons; buttons != NULL;
        buttons = buttons->next) {
        if (((hud_button_t *)buttons->data)->hidden == false &&
            sfIntRect_contains(&((hud_button_t *)buttons->data)->pos,
            mouse_pos.x + offset.x, mouse_pos.y + offset.y) == sfTrue &&
            used == false) {
            ((hud_button_t *)buttons->data)->hover = true;
            used = hud_event_button_click(((hud_button_t *)buttons->data),
            event);
        } else
            ((hud_button_t *)buttons->data)->hover = false;
    }
    return used;
}

int hud_event_mouse(hud_t *hud, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(hud->win);

    return hud_event_analyze_mouse_input(hud, event, mouse_pos,
    (sfVector2i){.x = 0, .y = 0});
}