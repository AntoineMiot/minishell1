/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

char **my_getenv_filepath(int i, int nb_path, char **envi)
{
    char **filepath;
    int j = 0;
    int k = 0;

    filepath = malloc(sizeof(char *) * (nb_path + 1));
    filepath[j] = malloc(sizeof(char) * my_strlen(envi[i]));
    for (int z = 5; envi[i][z] != '\0'; z++) {
        if (envi[i][z] == ':') {
            z++;
            filepath[j][k] = '\0';
            j++;
            filepath[j] = malloc(sizeof(char) * my_strlen(envi[i]));
            k = 0;
        }
        filepath[j][k] = envi[i][z];
        k++;
    }
    filepath[j + 1] = malloc(sizeof(char) * 1);
    filepath[j + 1][0] = '\0';
    return (filepath);
}

char **my_getenv(char **envi)
{
    int i = line_path(envi);
    int nb_path = my_getenv_nb_path(envi, i);

    return (my_getenv_filepath(i, nb_path, envi));
}

int line_oldpwd(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D'
            && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D'
            && env[i][6] == '=')
            return (i);
    }
}

int line_pwd(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'W'
            && env[i][2] == 'D' && env[i][3] == '=')
            return (i);
    }
}

int function_cdirectory_two(char **env, char **arg)
{
    if ((arg[1] == NULL || str_to_word_tab_two(arg[1], "~") == 0)
    && line_home(env) == -1) {
        my_putstr("cd: No home directory\n");
        return (7);
    }
}