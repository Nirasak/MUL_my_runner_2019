/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** runner
*/

#include <time.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"

bool init_struct(game_t *game, char *str)
{
    game->status = MENU;
    game->win = 0;
    create_player(&game->ness);
    if (my_strcmp(str, "-i") == 0)
        create_fire_infinite(&game->fire);
    else if (create_fire(&game->fire, str) == false)
        return (false);
    if (create_menu(&game->menu) == false)
        return (false);
    create_opt(&game->opt);
    if (create_parallax(&game->prlx) == false)
        return (false);
    if (create_ldb(&game->ldb) == false)
        return (false);
    create_music(game);
    create_score(&game->scr);
    return (true);
}

int my_runner(game_t *game, char *str)
{
    my_putstr("Please enter your name:\n");
    while ((game->pseudo = get_next_line(0)) == NULL);
    create_window(game);
    if (init_struct(game, str) == false)
        return (84);
    while (sfRenderWindow_isOpen(game->wdw)) {
        if (game->status == MENU)
            loop_menu(game);
        if (game->status == OPTIONS)
            loop_opt(game);
        if (game->status == GAME)
            loop_game(game, str);
        if (game->status == LDB)
            loop_ldb(game);
    }
    destroy_struct(game);
    sfRenderWindow_destroy(game->wdw);
    free(game->pseudo);
    return (0);
}
