/*
** EPITECH PROJECT, 2020
** create_music.c
** File description:
** create music
*/

#include "my.h"

void create_music(game_t *game)
{
    game->music = sfMusic_createFromFile("./music/music.ogg");
    sfMusic_setVolume(game->music, 50);
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
    game->click = sfMusic_createFromFile("./music/click.ogg");
    sfMusic_setVolume(game->click, 50);
}
