/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_calloc
*/

#include <stdlib.h>
#include "my.h"

void *my_memset(int size, char *str)
{
    char *ret = malloc(size);
    int len;

    if (ret == NULL)
        return NULL;
    if (str == NULL)
        len = -1;
    else
        len = my_strlen(str);
    for (int i = 0; i < size; i++) {
        if (i < len)
            ret[i] = str[i];
        else
            ret[i] = 0;
    }
    return (ret);
}
