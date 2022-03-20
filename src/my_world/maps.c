/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** maps
*/

#include "my_world.h"

int *char_arr_to_int_arr(char **arr)
{
    int *int_arr;
    int size = my_char_tabl_len(arr) - 1;

    if (size <= 0)
        return NULL;
    if ((int_arr = malloc(sizeof(int) * (size + 1))) == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        int_arr[i] = my_getnbr(arr[i]);
        my_printf("%d ", int_arr[i]);
    }
    write(1, "\n", 1);
    return int_arr;
}

int **char_arr_to_int_arr_arr(char **arr)
{
    int **int_arr;
    int size = my_char_tabl_len(arr) - 1;
    char **char_arr = NULL;

    if ((int_arr = malloc(sizeof(int *) * size)) == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        if ((char_arr = str_to_array(arr[i], " \0")) == NULL)
            return NULL;
        if ((int_arr[i] = char_arr_to_int_arr(char_arr)) == NULL)
            return NULL;
        free_char_arr(char_arr);
    }
    return int_arr;
}

static wd_game_t *get_map_value(wd_game_t *game, char **map_info)
{
    char **map_char = NULL;
    char **map_text_char = NULL;

    if ((map_char = str_to_array(map_info[0], "\n\0")) == NULL)
        return NULL;
    if ((map_text_char = str_to_array(map_info[1], "\n\0")) == NULL)
        return NULL;
    if ((game->map->map = char_arr_to_int_arr_arr(map_char)) == NULL)
        return NULL;
    if ((game->map->map_text = char_arr_to_int_arr_arr(map_text_char)) == NULL)
        return NULL;
    game->map->height = for_char_in_str(map_info[0], '\n') + 1;
    game->map->width = for_char_in_str(map_char[0], ' ') + 1;
    free_char_arr(map_char);
    free_char_arr(map_text_char);
    return game;
}

wd_game_t *parse_map(wd_game_t *game, char *filepath)
{
    char *map_str = file_to_str(filepath);
    char **map_info = NULL;

    my_printf("vvv\tvvv\tvvv %s\tvvv\tvvv\tvvv\tvvv\n", filepath);
    if (map_str == NULL) {
        my_printerr("\t\t>>> fail to load file %s\n", filepath);
        return NULL;
    }
    if ((map_info = str_to_array(map_str, "@\0")) == NULL ||
        map_info[0] == NULL || map_info[1] == NULL) {
        my_printerr("\t\t>>> fail to get map info\n");
        return NULL;
    }
    if ((game = get_map_value(game, map_info)) == NULL)
        return NULL;
    free_char_arr(map_info);
    free(map_str);
    return game;
}
