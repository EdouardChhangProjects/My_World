/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** contructor
*/

#include "hud.h"

bool hud_parser_bool(char *bool_constr)
{
    if (str_start_with(bool_constr, "true", my_strlen(bool_constr), 4) == 1)
        return true;
    return false;
}
