/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** get_keys
*/

#include "hud.h"

char **hud_parser_get_keys(char *keys)
{
    char **keys_arr = str_to_array(keys, ";");

    if (keys_arr == NULL)
        return NULL;
    return keys_arr;
}

char *hud_parser_get_key(char **keys_arr, char *key)
{
    int key_length = my_strlen(key);
    int i = 0;
    char *tmpstr = NULL;

    if (keys_arr == NULL || keys_arr[0] == NULL)
        return NULL;
    for (i = 0; str_start_with(keys_arr[i], key,
        key_length, key_length) == 0; i++) {
        if (keys_arr[i + 1] == NULL)
            return NULL;
    }
    tmpstr = keys_arr[i];
    for (; tmpstr[0] != '\0' && tmpstr[0] != '='; tmpstr++);
    for (; tmpstr[0] == ' ' || tmpstr[0] == '='; tmpstr++);
    my_printf("\t ==> %s = %s\n", key, tmpstr);
    return my_strdup(tmpstr);
}
