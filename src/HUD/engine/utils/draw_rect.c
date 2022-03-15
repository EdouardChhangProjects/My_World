/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** draw_rect
*/

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** create_rect
*/

#include "hud.h"

void hud_draw_vertexRect(sfRenderWindow *win, sfVertexArray *rect)
{
    sfRenderWindow_drawVertexArray(win, rect, NULL);
    sfVertexArray_destroy(rect);
}

void hud_draw_rect(sfRenderWindow *win, sfFloatRect pos, sfColor color,
sfVector2f view_pos)
{
    sfVertexArray *rect = hud_create_rect(pos, color, view_pos, NULL);

    hud_draw_vertexRect(win, rect);
}
