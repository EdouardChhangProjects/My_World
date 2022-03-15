/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** init
*/

#include "hud.h"

hud_t *hud_init_struct(sfRenderWindow *win, list_t *actions)
{
    hud_t *hud = malloc(sizeof(hud_t));

    if (hud == NULL)
        return NULL;
    hud->views = NULL;
    hud->buttons = NULL;
    hud->win = win;
    hud->actions = actions;
    return hud;
}

hud_t *hud_init(sfRenderWindow *win, list_t *actions, char *schemat_path)
{
    hud_t *hud = hud_init_struct(win, actions);
    char *schemat = file_to_str(schemat_path);

    hud_parser_extractor(schemat, hud);
    free(schemat);
    return hud;
}