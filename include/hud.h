/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** hud
*/

#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>
#include "list.h"
#include "my.h"
#include "printf.h"
#include "printerr.h"

#ifndef HUD_H
    #define HUD_H

typedef struct hud_button_s hud_button_t;

typedef struct hud_action_s {
    char *name;
    void (*function)(hud_button_t *self, void *param);
    void *param;
} hud_action_t;

typedef struct hud_button_s {
    sfIntRect pos;
    bool hidden;
    bool border;
    sfFloatRect borderWidth;
    sfColor borderColor;
    sfColor color;
    hud_action_t *action;
    sfTexture *texture;
    sfColor actionBorderColor;
    sfColor actionColor;
    bool toggleable;
    bool toggle;
    bool hover;
} hud_button_t;

typedef struct dropdown_s {
    unsigned int id;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    bool border;
    int borderWidth;
    int borderWidthUp;
    int borderWidthDown;
    int borderWidthLeft;
    int borderWidthRight;
    sfColor borderColor;
    sfColor color;
    list_t *views;
    list_t *buttons;
    list_t *dropdown;
    bool toggle;
    bool toogleOnOver;
} dropdown_t;

typedef struct view_s {
    unsigned int id;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    bool border;
    int borderWidth;
    int borderWidthUp;
    int borderWidthDown;
    int borderWidthLeft;
    int borderWidthRight;
    sfColor borderColor;
    sfColor color;
    list_t *views;
    list_t *buttons;
    list_t *dropdown;
} view_t;

typedef struct hud_s {
    list_t *views;
    list_t *buttons;
    sfRenderWindow *win;
    list_t *actions;
} hud_t;

char *file_to_str(char *filepath);
char *str_dup_from_to(char *base, char start, char end);
char **hud_parser_get_keys(char *keys);
char *hud_parser_get_key(char **keys_arr, char *key);
hud_t *hud_init_struct(sfRenderWindow *win, list_t *actions);
hud_t *hud_init(sfRenderWindow *win, list_t *actions, char *schemat_path);
void hud_render_buttons(hud_t *hud);
void hud_render(hud_t *hud);
int hud_parser_extractor(char *schemat, hud_t *hud);
bool hud_parser_bool(char *bool_constr);
sfIntRect hud_parser_int_rect(char *rect_constr);
sfFloatRect hud_parser_float_rect(char *rect_constr);
sfColor hud_parser_sfcolor(char *color_constr);
const char *hud_parser_button_parser(char *schemat, hud_t *hud);
char *hud_parser_skip_balise(char *schemat);
sfVertexArray *hud_create_rect(sfFloatRect pos, sfColor color,
sfVector2f view_pos, sfTexture *texture);
void hud_draw_vertexRect(sfRenderWindow *win, sfVertexArray *rect);
void hud_draw_rect(sfRenderWindow *win, sfFloatRect pos, sfColor color,
sfVector2f view_pos);
sfTexture *hud_texture_set(char *path);
list_t *hud_action_append(list_t *actions, char *name,
void (*function)(hud_button_t *self, void *param), void *param);
hud_action_t *hud_action_get(hud_t *hud, char *name);
int hud_event_mouse(hud_t *hud, sfEvent *event);
int hud_event(hud_t *hud, sfEvent *event);
hud_button_t *hud_button_init(void);
void hud_button_render(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos);
void hud_button_set_pos(hud_button_t *button, int x, int y);
void hud_button_set_size(hud_button_t *button, int x, int y);
void hud_button_set_border_size(hud_button_t *button, sfFloatRect borderWidth);
void free_char_arr(char **arr);

#endif
