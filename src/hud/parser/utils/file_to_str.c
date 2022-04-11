/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** file_to_str
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int get_file_size(const char *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
    char buff[1];
    int size = 0;

    if (filedesc < 0)
        return -1;
    for (; read(filedesc, buff, 1) > 0; size++);
    close(filedesc);
    return size - 1;
}

char *file_to_str(char *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
    char *buff = NULL;
    int size = 1;

    if (filedesc < 0)
        return NULL;
    if ((size = get_file_size(filepath)) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (size + 2));
    if (read(filedesc, buff, size) < 1)
        return NULL;
    buff[size] = '\n';
    buff[size + 1] = '\0';
    close(filedesc);
    return buff;
}