/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

int line_user(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'U' && env[i][1] == 'S' && env[i][2] == 'E'
            && env[i][3] == 'R' && env[i][4] == '=')
            return (i);
    }
}

int line_home(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
            && env[i][3] == 'E' && env[i][4] == '=')
            return (i);
    }
    return (-1);
}

int line_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
            && env[i][3] == 'H' && env[i][4] == '=')
            return (i);
    }
    return (-1);
}

void disp_env(char **env)
{
    for (int i = 0; env[i+1] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar(10);
    }
}

int my_getenv_nb_path(char **envi, int i)
{
    int nb_path = 1;

    for (int z = 0; envi[i][z] != '\0'; z++)
        if (envi[i][z] == ':')
            nb_path++;
    return (nb_path);
}