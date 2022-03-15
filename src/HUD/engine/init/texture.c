/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** sprite
*/

#include "hud.h"
#include <fcntl.h>

sfTexture *hud_texture_set(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return NULL;
    close(fd);
    return sfTexture_createFromFile(path, NULL);
}
