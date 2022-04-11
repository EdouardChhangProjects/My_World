/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** extractor
*/

#include "hud.h"

static const int nb_balises = 1;
static const char *balises[] = {"<button"};
static const char *(*balises_func[])(char *, hud_t *) = {
    &hud_parser_button_parser
};

char *hud_parser_extractor_ignore(char *schemat)
{
    int i = 0;

    for (i = 0; schemat[i] == ' ' || schemat[i] == '\n' || schemat[i] == '\t';
        i++);
    schemat = &schemat[i];
    return schemat;
}

int hud_parser_get_balise(char *schemat)
{
    int balise_length = 0;

    for (int i = 0; i < nb_balises; i++) {
        balise_length = my_strlen(balises[i]);
        if (str_start_with(schemat, balises[i], balise_length,
            balise_length) == 1) {
            my_printf("\nfound balises: %s\n", &balises[i][1]);
            return i;
        }
    }
    my_printerr("unknow balise: %15s\n", schemat);
    return -1;
}

int hud_parser_extractor(char *schemat, hud_t *hud)
{
    int type = 0;

    while (schemat != NULL && schemat[0] != '\0') {
        schemat = hud_parser_extractor_ignore(schemat);
        if (schemat[0] == '\0' || (schemat[1] == '\0'))
            break;
        type = hud_parser_get_balise(schemat);
        if (type == -1) {
            schemat = hud_parser_skip_balise(schemat);
            continue;
        }
        schemat = &schemat[my_strlen(balises[type])];
        schemat = balises_func[type](schemat, hud);
    }
    my_printf("=================HUD PARSING SUCCESFULL=================\n\n\n");
    return 0;
}