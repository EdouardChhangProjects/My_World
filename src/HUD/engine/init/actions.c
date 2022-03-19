/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** actions
*/

#include "hud.h"

list_t *hud_action_append(list_t *actions, char *name,
void (*function)(hud_button_t *self, void *param), void *param)
{
    hud_action_t *action = malloc(sizeof(hud_action_t));

    if (action == NULL)
        return NULL;
    action->function = function;
    action->param = param;
    action->name = name;
    actions = list_append(actions, action);
    return actions;
}

hud_action_t *hud_action_get(hud_t *hud, char *name)
{
    list_t *actions = hud->actions;

    for (; actions != NULL; actions = actions->next) {
        if (my_strcmp(name, ((hud_action_t *)actions->data)->name) == 0) {
            return actions->data;
        }
    }
    my_printerr("\t\t>>> action not found: %s\n", name);
    return NULL;
}