/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_circle
*/

#include "my_world.h"

sfCircleShape *init_circle(float radius)
{
    sfCircleShape *dest = sfCircleShape_create();

    sfCircleShape_setRadius(dest, radius);
    sfCircleShape_setOrigin(dest, (sfVector2f){radius, radius});
    sfCircleShape_setFillColor(dest, sfWhite);
    return dest;
}
