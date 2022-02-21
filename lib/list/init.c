/*
** EPITECH PROJECT, 2022
** structure
** File description:
** init list (only one elem)
*/

#include "list.h"

list_t *list_init(void *data)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->next = NULL;
    list->prev = NULL;
    list->data = data;
    return list;
}

list_t *list_init_circ(void *data)
{
    list_t *list = list_init(data);

    if (list == NULL)
        return NULL;
    list->next = list;
    list->prev = list;
    return list;
}

/*
list_quad_t *list_init_quad(void *data)
{
    list_quad_t *list = malloc(sizeof(list_t));

    list->up = NULL;
    list->down = NULL;
    list->left = NULL;
    list->right = NULL;
    list->data = data;
    return list;
}

list_quad_t *list_init_circ_quad(void *data)
{
    list_quad_t *list = list_init_quad(data);

    list->up = list;
    list->down = list;
    list->left = list;
    list->right = list;
    return list;
}
*/