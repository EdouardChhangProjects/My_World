/*
** EPITECH PROJECT, 2021
** runner
** File description:
** init_game
*/

#include <fcntl.h>

#include "my_world.h"

int print_help(void)
{
    int fd = open(HELP, O_RDONLY);
    char buffer[394];

    if (read(fd, buffer, 393) != -1)
        write(1, buffer, 393);
    else
        return my_printerr("./my_runner: Failed to load help file\n");
    close(fd);
    return 0;
}
