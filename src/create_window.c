/*
** EPITECH PROJECT, 2019
** create_window.c
** File description:
** create window
*/

#include "my.h"

void create_window(game_t *game)
{
    sfVideoMode vm = {1920, 1080, 32};

    game->wdw = sfRenderWindow_create(
        vm, "my_runner", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->wdw, 120);
    sfRenderWindow_setVerticalSyncEnabled(game->wdw, sfTrue);
}
