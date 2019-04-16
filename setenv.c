/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell1 setenv funciton
*/
#include "include/my.h"

char **rewrite_env_two_two(char **env, char **arg)
{
    char *new_line;
    char **tmp_env;
    int i = 0;
    int z = 0;

    new_line = my_strcat(arg[1], "=");
    tmp_env = malloc(sizeof(char *) * (len_tab(env)+1));
    for (i; i != len_tab(env); i++) {
        tmp_env[i] = malloc(sizeof(char) * (my_strlen(env[i])+1));
        for (z; env[i][z] != '\0'; z++) {
            tmp_env[i][z] = env[i][z];
        }
        tmp_env[i][z] = '\0';
        z = 0;
    }
    tmp_env[i] = malloc(sizeof(char) * my_strlen(new_line));
    tmp_env[i] = my_strcpy(tmp_env[i], new_line);
    tmp_env[i+1] = malloc(sizeof(char));
    tmp_env[i+1] = NULL;
    env = rewrite_env_two(tmp_env, env);
    return (env);
}

char **rewrite_env(char **env, char **arg)
{
    char *new_line;
    char **tmp_env;
    int i = 0;
    int z = 0;

    new_line = my_strcat(arg[1], my_strcat("=", arg[2]));
    tmp_env = malloc(sizeof(char *) * (len_tab(env)+1));
    for (i; i != len_tab(env); i++) {
        tmp_env[i] = malloc(sizeof(char) * (my_strlen(env[i])+1));
        for (z; env[i][z] != '\0'; z++) {
            tmp_env[i][z] = env[i][z];
        }
        tmp_env[i][z] = '\0';
        z = 0;
    }
    tmp_env[i] = malloc(sizeof(char) * my_strlen(new_line));
    tmp_env[i] = my_strcpy(tmp_env[i], new_line);
    tmp_env[i+1] = malloc(sizeof(char));
    tmp_env[i+1] = NULL;
    env = rewrite_env_two(tmp_env, env);
    return (env);
}

char **setenv_funct_two(char **arg, char **env)
{
    char **tmp_env;
    int first = 0;

    tmp_env = new_env_tab(tmp_env, env);
    for (int i = 0; tmp_env[i] != NULL; i++) {
        if (str_to_word_tab_two(tmp_env[i], arg[1]) == 0) {
            rewrite_line_tab(arg, i, env, tmp_env[i]);
            first = 1;
        }
    }
    if (first == 0)
        env = rewrite_env(env, arg);
    return (env);
}

char **setenv_funct_three(char **arg, char **env)
{
    int first = 0;
    char **tmp_env;

    tmp_env = new_env_tab(tmp_env, env);
    for (int i = 0; tmp_env[i] != NULL; i++) {
        if (str_to_word_tab_two(tmp_env[i], arg[1]) == 0) {
            rewrite_line_tab_two(arg, i, env, tmp_env[i]);
            first = 1;
        }
    }
    if (first == 0)
        env = rewrite_env_two_two(env, arg);
    return (env);
}

char **setenv_funct(char **arg, char **env)
{
    if (len_tab(arg) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (env);
    }
    if (len_tab(arg) == 3)
        env = setenv_funct_two(arg, env);
    if (len_tab(arg) == 2)
        env = setenv_funct_three(arg, env);
    if (len_tab(arg) == 1)
        disp_env(env);
    return (env);
}