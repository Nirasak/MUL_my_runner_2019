/*
** EPITECH PROJECT, 2020
** create_fire.c
** File description:
** create fire
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "my.h"

void set_fire(fire_t *fire)
{
    fire->nb_fire = 0;
    fire->s_fire = sfSprite_create();
    fire->t_fire = sfTexture_createFromFile("assets/fire.png", NULL);
    sfSprite_setTexture(fire->s_fire, fire->t_fire, sfTrue);
    fire->r_fire.left = 0;
    fire->r_fire.top = 0;
    fire->r_fire.width = 50;
    fire->r_fire.height = 120;
    sfSprite_setTextureRect(fire->s_fire, fire->r_fire);
    fire->c_fire = sfClock_create();
    fire->sec_fire = 0;
}

bool create_fire_infinite(fire_t *fire)
{
    set_fire(fire);
    fire->nb_fire = 500;
    fire->p_fire = malloc(sizeof(sfVector2f) * (fire->nb_fire + 1));
    if (fire->p_fire == NULL)
        return (false);
    for (int i = 0; i < fire->nb_fire; i++) {
        fire->p_fire[i].x = i * 500 + 800;
        fire->p_fire[i].y = 865;
    }
    return (true);
}

bool create_fire(fire_t *fire, char *str)
{
    int fd = open(str, O_RDONLY);
    char *map = NULL;
    int j = 0;

    set_fire(fire);
    if ((map = get_next_line(fd)) == NULL)
        return (false);
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '1')
            fire->nb_fire++;
    if ((fire->p_fire =
        malloc(sizeof(sfVector2f) * (fire->nb_fire + 1))) == NULL)
        return (false);
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '1') {
            fire->p_fire[j].x = i * 120 + 800;
            fire->p_fire[j].y = 865;
            j++;
        }
    return (true);
}
