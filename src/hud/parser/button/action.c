/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** action
*/

#include "hud.h"

hud_button_t *hud_parser_button_set_action(hud_t *hud, hud_button_t *button,
const char *name)
{
    for (list_t *action = hud->actions; action != NULL; action = action->next) {
        if (my_strcmp(((hud_action_t*)action->data)->name, name) == 0) {
            button->action = ((hud_action_t*)action->data);
            return button;
        }
    }
    my_printerr("\t -> action '%s' does not exist", name);
    return button;
}