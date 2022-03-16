/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** create_rect
*/

#include "hud.h"

sfVertexArray *hud_create_rect(sfFloatRect pos, sfColor color,
sfVector2f view_pos, sfTexture *texture)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2u texture_size;
    sfVertex vertex1 = {.position = {.x = pos.left + view_pos.x,
    .y = pos.top + view_pos.y}, .color = color};
    sfVertex vertex2 = {.position = {.x = pos.left + pos.width + view_pos.x,
    .y = pos.top + view_pos.y}, .color = color};
    sfVertex vertex3 = {.position = {.x = pos.left + pos.width + view_pos.x,
    .y = pos.top + pos.height + view_pos.y}, .color = color};
    sfVertex vertex4 = {.position = {.x = pos.left + view_pos.x,
    .y = pos.top + pos.height + view_pos.y}, .color = color};

    if (texture != NULL) {
        texture_size = sfTexture_getSize(texture);
        vertex1.texCoords = (sfVector2f){.x = 0, .y = 0};
        vertex2.texCoords = (sfVector2f){.x = (float)texture_size.x, .y = 0};
        vertex3.texCoords = (sfVector2f){.x = (float)texture_size.x,
        .y = (float)texture_size.y};
        vertex4.texCoords = (sfVector2f){.x = 0, .y = (float)texture_size.y};
    }
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}