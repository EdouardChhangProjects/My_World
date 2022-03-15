/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** constructor
*/

#include "hud.h"

sfIntRect hud_parser_int_rect(char *rect_constr)
{
    sfIntRect rect;
    char **arr = str_to_array(rect_constr, ":");
    int nbrs[] = {0, 0, 0, 0};

    if (arr == NULL)
        return (sfIntRect){.left = -1, .top = -1, .width = -1, .height = -1};
    for (int i = 0; i < 4; i++) {
        if (arr[i] == NULL)
            return (sfIntRect){.left = -1, .top = -1,
            .width = -1, .height = -1};
        nbrs[i] = my_getnbr(arr[i]);
    }
    rect = (sfIntRect){.left = nbrs[0], .top = nbrs[1],
    .width = nbrs[2], .height = nbrs[3]};
    return rect;
}

sfFloatRect hud_parser_float_rect(char *rect_constr)
{
    sfFloatRect rect;
    char **arr = str_to_array(rect_constr, ":");
    float nbrs[] = {0.0, 0.0, 0.0, 0.0};

    if (arr == NULL)
        return (sfFloatRect){.left = -1, .top = -1, .width = -1, .height = -1};
    for (int i = 0; i < 4; i++) {
        if (arr[i] == NULL)
            return (sfFloatRect){.left = -1, .top = -1,
            .width = -1, .height = -1};
        nbrs[i] = (float)my_getnbr(arr[i]);
    }
    rect = (sfFloatRect){.left = nbrs[0], .top = nbrs[1],
    .width = nbrs[2], .height = nbrs[3]};
    return rect;
}

sfColor hud_parser_sfcolor(char *color_constr)
{
    sfColor rect;
    char **arr = str_to_array(color_constr, ":");
    int nbrs[] = {0, 0, 0, 0};

    if (arr == NULL)
        return (sfColor){.r = -1, .g = -1, .b = -1, .a = -1};
    for (int i = 0; i < 4; i++) {
        if (arr[i] == NULL)
            return (sfColor){.r = -1, .g = -1, .b = -1, .a = -1};
        nbrs[i] = my_getnbr(arr[i]);
    }
    rect = (sfColor){.r = nbrs[0], .g = nbrs[1], .b = nbrs[2], .a = nbrs[3]};
    return rect;
}