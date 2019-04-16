/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell1 setenv funciton
*/
#include "include/my.h"

char **rewrite_env_two(char **tmp_env, char **env)
{
    int i = 0;
    int z = 0;

    env = malloc(sizeof(char *) * len_tab(tmp_env));
    for (i; i != len_tab(tmp_env); i++) {
        env[i] = malloc(sizeof(char) * (my_strlen(tmp_env[i])+1));
        for (z; tmp_env[i][z] != '\0'; z++) {
            env[i][z] = tmp_env[i][z];
        }
        env[i][z] = '\0';
        z = 0;
    }
    return (env);
}