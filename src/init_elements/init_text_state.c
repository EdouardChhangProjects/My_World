/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_text_state
*/

#include "my_world.h"

sfRenderStates *init_text_state(wd_spritetype_e type)
{
    char *spritefile[] = {"assets/basic_green.png",
            "assets/swamp_set.png",
            "assets/ice_set.png",
            "assets/fire_set.png"};
    sfRenderStates *states = my_memset(sizeof(sfRenderStates), NULL);
    sfTexture *texture = sfTexture_createFromFile(spritefile[type],
    NULL);

    if (texture == NULL || states == NULL) {
        return NULL;
    }
    states->shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_Identity;
    states->texture = texture;
    return states;
}
