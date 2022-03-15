/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** event
*/

#include "hud.h"

void hud_event(hud_t *hud, sfEvent *event)
{
    hud_event_mouse(hud, event);
}