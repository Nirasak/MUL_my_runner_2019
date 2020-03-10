/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <unistd.h>
#include "my.h"

int print_descr(char *exe)
{
    my_putstr("Finite runner created with CSFML\n\n");
    my_putstr("USAGE\n ");
    my_putstr(exe);
    my_putstr(" map.txt\n\n\nOPTIONS\n");
    my_putstr(" -i\t\tlaunch the game in infinity mode\n");
    my_putstr(" -h\t\tprint the usage and quit\n\n");
    my_putstr("USER INTERACTIONS\n SPACE_KEY\tjump\n");
    return (0);
}

int main(int ac, char **av, char **env)
{
    game_t game;

    if (env[0] == NULL)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_descr(av[0]));
    if (ac == 2)
        return (my_runner(&game, av[1]));
    return (84);
}
