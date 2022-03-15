/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** create_rect
*/

#include "hud.h"

sfVertexArray *hud_create_rect(sfFloatRect pos, sfColor color,
sfVector2f view_pos)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = {.x = pos.left + view_pos.x,
    .y = pos.top + view_pos.y}, .color = color};
    sfVertex vertex2 = {.position = {.x = pos.left + pos.width + view_pos.x,
    .y = pos.top + view_pos.y}, .color = color};
    sfVertex vertex3 = {.position = {.x = pos.left + pos.width + view_pos.x,
    .y = pos.top + pos.height + view_pos.y}, .color = color};
    sfVertex vertex4 = {.position = {.x = pos.left + view_pos.x,
    .y = pos.top + pos.height + view_pos.y}, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}