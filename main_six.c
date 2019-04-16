/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

char **function_cdirectory_three(path *pth, char **env, char *home_str)
{
    char cwd[PATH_MAX];
    struct stat s;

    pth->pwd = my_strcpy(pth->pwd, getcwd(cwd, sizeof(cwd)));
    if (stat(home_str + 5, &s) != -1)
        chdir(home_str + 5);
    env[line_pwd(env)] = my_strcat("PWD=", getcwd(cwd, sizeof(cwd)));
    return (env);
}

char **function_cdirectory_four(path *pth, char **env, char *tmp_oldpwd)
{
    struct stat s;
    char cwd[PATH_MAX];

    if (stat(pth->pwd, &s) != -1) {
        chdir(pth->pwd);
        pth->pwd = my_strcpy(pth->pwd, tmp_oldpwd);
        env[line_pwd(env)] = my_strcat("PWD=", getcwd(cwd, sizeof(cwd)));
    } else {
        my_putstr(": No such file or directory.\n");
    }
    return (env);
}

char **function_cdirectory_five(char **arg, path *pth, char **env)
{
    struct stat s;
    char cwd[PATH_MAX];

    if (stat(arg[1], &s) != -1) {
        pth->pwd = my_strcpy(pth->pwd, getcwd(cwd, sizeof(cwd)));
        chdir(arg[1]);
        env[line_pwd(env)] = my_strcat("PWD=", getcwd(cwd, sizeof(cwd)));
    } else {
        my_putstr(arg[1]);
        my_putstr(": No such file or directory.\n");
    }
    return (env);
}

int function_cdirectory_six(char **arg)
{
    if (opendir(arg[1]) == NULL
    && str_to_word_tab_two(arg[1], "..") != 0
    && errno == EACCES) {
        my_putstr(arg[1]);
        my_putstr(": Permission denied.\n");
        return (84);
    }
    return (0);
}

int function_cdirectory(char **arg, char **env, char *home_str,
struct path *pth)
{
    char *tmp_pwd;
    char *tmp_oldpwd;
    char cwd[PATH_MAX];

    if (function_cdirectory_two(env, arg) == 7)
        return (7);
    if (arg[1] == NULL || str_to_word_tab_two(arg[1], "~") == 0) {
        env = function_cdirectory_three(pth, env, home_str);
    } else if (str_to_word_tab_two(arg[1], "-") == 0) {
        tmp_oldpwd = my_strcpy(tmp_oldpwd, getcwd(cwd, sizeof(cwd)));
        env = function_cdirectory_four(pth, env, tmp_oldpwd);
    } else {
        if (function_cdirectory_six(arg) == 84)
            return (84);
        function_cdirectory_five(arg, pth, env);
    }
}