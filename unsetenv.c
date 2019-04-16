/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell1 unsetenv funciton
*/

#include "include/my.h"
#include <unistd.h>

int check_same_line(char **arg, char *str)
{
    for (int i = 1; i != len_tab(arg); i++) {
        if (str_to_word_tab_two(arg[i], str) == 0) {
            return (0);
        }
    }
    return (1);
}

char **new_env_array(char **env, char **tmp_env_arg, char **arg)
{
    int i = 0;
    int j = 0;
    int z = 0;
    char **tmp_env;

    tmp_env = malloc(sizeof(char *) * (len_tab(env)-(len_tab(arg))));
    for (i = i; i != len_tab(env) - len_tab(arg); i++) {
        while (check_same_line(arg, tmp_env_arg[j]) == 0)
            j++;
        tmp_env[i] = my_strcpy(tmp_env[i], env[j]);
        z = 0;
        j++;
    }
    tmp_env[i] = my_strcpy(tmp_env[i], env[j]);
    tmp_env[i+1] = NULL;
    env = malloc(sizeof(char*) * (len_tab(tmp_env) + 1));
    for (i = 0; i != len_tab(tmp_env); i++) {
        env[i] = my_strcpy(env[i], tmp_env[i]);
    }
    env[i] = NULL;
    return (env);
}

char **unsetenv_funct(char **arg, char **env)
{
    char **tmp_env_arg;
    int i = 0;
    int z = 0;

    tmp_env_arg = new_env_tab(tmp_env_arg, env);
    env = new_env_array(env, tmp_env_arg, arg);
    return (env);
}
