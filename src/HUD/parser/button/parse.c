/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** parse
*/

#include "hud.h"

static void hud_parser_button_get_value_3(hud_button_t *button,
char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "color")) != NULL) {
        button->color = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "borderColor")) != NULL) {
        button->borderColor = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "actionColor")) != NULL) {
        button->color = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "actionBorderColor")) != NULL) {
        button->borderColor = hud_parser_sfcolor(key);
        free(key);
    }
}

static void hud_parser_button_get_value_2(hud_button_t *button,
char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "border")) != NULL) {
        button->border = hud_parser_bool(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "toggleable")) != NULL) {
        button->toggleable = hud_parser_bool(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "toggle")) != NULL) {
        button->toggle = hud_parser_bool(key);
        free(key);
    }
    hud_parser_button_get_value_3(button, keys);
}

void hud_parser_button_get_value(hud_button_t *button, char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "pos")) != NULL) {
        button->pos = hud_parser_int_rect(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "borderWidth")) != NULL) {
        button->borderWidth = hud_parser_float_rect(key);
        free(key);
    }
    hud_parser_button_get_value_2(button, keys);
}

void hud_parser_button_get_action(hud_t *hud, hud_button_t *button, char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "action")) != NULL) {
        button->action = hud_action_get(hud, key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "texture")) != NULL) {
        button->texture = hud_texture_set(key);
        free(key);
    }
}

char *hud_parser_button_parser(char *schemat, hud_t *hud)
{
    hud_button_t *button = hud_button_init();
    char **keys = NULL;
    char *keystr = str_dup_from_to(schemat, '@', '@');

    if (keystr == NULL)
        return schemat;
    keys = hud_parser_get_keys(keystr);
    schemat = hud_parser_skip_balise(schemat);
    if (schemat[0] != '\0')
        schemat++;
    hud_parser_button_get_value(button, keys);
    hud_parser_button_get_action(hud, button, keys);
    hud->buttons = list_append(hud->buttons, button);
    return schemat;
}