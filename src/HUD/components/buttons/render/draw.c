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

void hud_button_render_sprite(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos)
{
    if (button->sprite == NULL)
        return;
    
    sfSprite_setPosition(button->sprite->sprite, (sfVector2f){
    .x = button->pos.left + view_pos.x,
    .y = button->pos.width + view_pos.y});
    sfSprite_setTextureRect(button->sprite->sprite, button->pos);
    sfSprite_setTexture(button->sprite->sprite, button->sprite->texture,
    sfTrue);
    sfRenderWindow_drawSprite(win, button->sprite->sprite, NULL);
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
    hud_button_render_sprite(win, button, view_pos);
}