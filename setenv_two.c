/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell1 setenv funciton
*/
#include "include/my.h"

int len_before_equal(char *str)
{
    int i = 0;

    for (i; str[i] != '='; i++);
    return (i);
}

int len_tab(char **env)
{
    int i = 0;

    for (i; env[i] != NULL; i++);
    return (i);
}

char **new_env_tab(char **tmp_env, char **env)
{
    int i = 0;
    int z = 0;

    tmp_env = malloc(sizeof(char *) * (len_tab(env)+1));
    for (i; i != len_tab(env); i++) {
        tmp_env[i] = malloc(sizeof(char) * (len_before_equal(env[i])+1));
        for (z; z != len_before_equal(env[i]); z++) {
            tmp_env[i][z] = env[i][z];
        }
        tmp_env[i][z] = '\0';
        z = 0;
    }
    tmp_env[i] = NULL;
    return (tmp_env);
}

void rewrite_line_tab_two(char **arg, int i, char **env, char *tmp_env)
{
    char *str_tmp;

    str_tmp = my_strcat(arg[1], "=");
    env[i] = my_strcpy(env[i], str_tmp);
}

void rewrite_line_tab(char **arg, int i, char **env, char *tmp_env)
{
    char *str_tmp;

    str_tmp = my_strcat(arg[1], "=");
    env[i] = my_strcat(str_tmp, arg[2]);
}