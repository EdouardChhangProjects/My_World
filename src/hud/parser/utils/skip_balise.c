/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** skip_balise
*/

#include "hud.h"

char *hud_parser_skip_balise(char *schemat)
{
    while (str_start_with(schemat, "/>", my_strlen(schemat), 2) != 1) {
        schemat++;
        if (schemat[0] == '\0')
            return NULL;
    }
    if (schemat[0] != '\0')
        schemat++;
    return schemat;
}
