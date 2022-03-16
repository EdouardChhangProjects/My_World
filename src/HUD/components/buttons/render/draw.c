/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** draw
*/

#include "hud.h"

static void hud_button_render_border(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos)
{
    sfColor color;

    if (button->toggle == true ^ button->hover == true) {
        color = button->actionBorderColor;
    } else
        color = button->borderColor;
    hud_draw_rect(win, (sfFloatRect){.left = button->pos.left,
    .top = button->pos.top, .width = button->pos.width,
    .height = button->pos.height}, color, view_pos);
}

// taille texture = taille boutton / taille texture

// static

/* sfRenderStates *init_text_state(sfTexture *texture)
{
    sfRenderStates *states = my_memset(sizeof(sfRenderStates), NULL);

    if (texture == NULL || states == NULL) {
        return NULL;
    }
    states->shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_Identity;
    states->texture = texture;
    return states;
} */

void hud_button_render_texture(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos)
{
    sfVertexArray *rect = NULL;
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    if (button->texture == NULL)
        return;
    rect = hud_create_rect((sfFloatRect){
    .left = button->pos.left, .top = button->pos.top,
    .width = button->pos.width, .height = button->pos.height}, sfWhite,
    view_pos, button->texture);
    states->shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_Identity;
    states->texture = button->texture;
    sfRenderWindow_drawVertexArray(win, rect, states);
    sfVertexArray_destroy(rect);
}

static sfColor hud_button_get_color(hud_button_t *button)
{
    sfColor color;

    if (button->toggle == true ^ button->hover == true) {
        color = button->actionColor;
    } else
        color = button->color;
    return color;
}

void hud_button_render(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos)
{
    sfColor color = hud_button_get_color(button);

    if (button->hidden == true)
        return;
    if (button->border == true) {
        hud_button_render_border(win, button, view_pos);
        hud_draw_rect(win, (sfFloatRect){.left = button->pos.left +
        button->borderWidth.left, .top = button->pos.top +
        button->borderWidth.top, .width = (button->pos.width -
        button->borderWidth.left) - button->borderWidth.width,
        .height = (button->pos.height - button->borderWidth.top) -
        button->borderWidth.height}, color, view_pos);
        return;
    }
    hud_draw_rect(win, (sfFloatRect){.left = button->pos.left,
    .top = button->pos.top, .width = button->pos.width,
    .height = button->pos.height}, color, view_pos);
    hud_button_render_texture(win, button, view_pos);
}