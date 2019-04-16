/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

int bultin_scnd(char **filepath, char **envi, char **arg)
{
    int status;
    pid_t tmp;

    for (int i = 0; filepath[i][0] != '\0'; i++) {
        if (len_tab(envi) != 1)
            filepath[i] = my_strcat(filepath[i], my_strcat("/", arg[0]));
        if (access(filepath[i], F_OK) == 0) {
            tmp = fork();
            bultin_scnd_two(tmp, filepath[i], arg, envi);
            waitpid(tmp, &status, WUNTRACED | WCONTINUED);
            disp_segaultf(status);
            return (1);
        }
    }
    return (-1);
}

int bultin(char **arg, char **envi)
{
    char **filepath;
    int j;

    if (line_path(envi) != -1)
        filepath = my_getenv(envi);
    else {
        my_putstr(arg[0]);
        my_putstr(": Command not found.\n");
        return (2);
    }
    j = bultin_scnd(filepath, envi, arg);
    if (j == -1) {
        my_putstr(arg[0]);
        my_putstr(": Command not found.\n");
    }
}

int test_bultin(char **arg)
{
    char *bultin[5] = {"cd", "setenv", "unsetenv", "env", "exit"};

    for (int i = 0; i != 5; i++) {
        if (str_to_word_tab_two(arg[0], bultin[i]) == 0) {
            return (0);
        }
    }
    return (1);
}

char **new_env(char **env, char **envi)
{
    int i = 0;

    envi = malloc(sizeof(char *) * (len_tab(env) + 1));
    for (i; env[i] != NULL; i++)
        envi[i] = my_strcpy(envi[i], env[i]);
    envi[i] = NULL;
    return (envi);
}

void main_three(char **arg, char **envi)
{
    if (arg[0][0] == '.' && arg[0][1] == '/' || arg[0][0] == '/')
        bultin_two(arg, envi);
    else
        bultin(arg, envi);
}