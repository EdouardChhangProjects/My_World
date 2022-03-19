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
    hud_t *hud = NULL;
    char *schemat = file_to_str(schemat_path);

    my_printf("===\t===\t=== %s ===\t===\t===\t===\n", schemat_path);
    if (schemat == NULL) {
        my_printerr("\t\t>>> fail to load file %s\n", schemat_path);
        return NULL;
    }
    if ((hud = hud_init_struct(win, actions)) == NULL) {
        my_printerr("\t\t>>> fail to init: %s\n", schemat_path);
        return NULL;
    }
    if (hud_parser_extractor(schemat, hud) != 0)
        return NULL;
    free(schemat);
    return hud;
}