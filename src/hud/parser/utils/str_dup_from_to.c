/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** str_dup_from_to
*/

#include "hud.h"

char *str_dup_from_to(char *base, char start, char end)
{
    int i = 0;
    char *res = NULL;

    for (; base[0] != '\0' && base[0] != start; base++);
    base++;
    for (i = 0; base[i] != '\0' && base[i] != end; i++);

    res = my_strndup(base, i);
    return res;
}