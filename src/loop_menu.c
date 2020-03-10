/*
** EPITECH PROJECT, 2019
** loop_menu.c
** File description:
** loop menu
*/

#include "my.h"

void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->wdw, sfBlack);
    sfRenderWindow_drawSprite(game->wdw, game->menu.s_menu, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->wdw, game->menu.s_butt[i], NULL);
}

void loop_menu(game_t *game)
{
    sfEvent event;

    while (game->status == MENU && sfRenderWindow_isOpen(game->wdw)) {
        while (sfRenderWindow_pollEvent(game->wdw, &event))
            my_events_menu(game, event);
        display_menu(game);
        sfRenderWindow_display(game->wdw);
    }
}
