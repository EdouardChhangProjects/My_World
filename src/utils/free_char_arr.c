/*
** EPITECH PROJECT, 2022
** boggle
** File description:
** free_char_arr
*/

#include <unistd.h>
#include <stdlib.h>

void free_char_arr(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}
