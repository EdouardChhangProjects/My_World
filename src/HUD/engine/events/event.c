/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** event
*/

#include "hud.h"

int hud_event(hud_t *hud, sfEvent *event)
{
    return hud_event_mouse(hud, event);
}