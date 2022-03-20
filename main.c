/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard [WSL: Arch]
** File description:
** main
*/

#include "my_world.h"

int main(int ac, char **av, char **env)
{
    if (check_env(env) == 84)
        return my_printerr("./my_runner: Cannot open display\n");
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h')
        return print_help();
    if (ac >= 1 && ac <= 2)
        return my_world(av, ac);
    return my_printerr("./my_runner: Invalid arguments\n");
}
