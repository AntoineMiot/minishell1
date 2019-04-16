/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

char **distrib_builtin(char **arg, char **env, char *home_str, struct path *pth)
{
    if (str_to_word_tab_two(arg[0], "cd") == 0)
        function_cdirectory(arg, env, home_str, pth);
    if (str_to_word_tab_two(arg[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (str_to_word_tab_two(arg[0], "env") == 0)
        disp_env(env);
    if (str_to_word_tab_two(arg[0], "setenv") == 0)
        env = setenv_funct(arg, env);
    if (str_to_word_tab_two(arg[0], "unsetenv") == 0)
        env = unsetenv_funct(arg, env);
    return (env);
}

void disp_segaultf(int status)
{
    if (WIFSIGNALED(status) > 0) {
        if (WTERMSIG(status) == 8) {
            my_putstr("Floating exception");
            (WCOREDUMP(status)) ? my_putstr(" (core dumped)\n") :
            my_putchar('\n');
        }
        if (WTERMSIG(status) == 11 || WTERMSIG(status) == 139) {
            my_putstr("Segmentation fault");
            (WCOREDUMP(status)) ? my_putstr(" (core dumped)\n") :
            my_putchar('\n');
        }
    }
}

void bultin_two_two(int tmp, char **arg, char **envi)
{
    if (tmp == 0) {
        if (execve(arg[0], arg, envi) == -1) {
            my_putstr(arg[0]);
            my_putstr(": Exec format error. Wrong Architecture.\n");
            exit(0);
        }
    }
}

int bultin_two(char **arg, char **envi)
{
    struct dirent *pDirent;
    DIR *pDir;
    int status;
    pid_t tmp;

    if (access(arg[0], F_OK) == 0) {
        tmp = fork();
        bultin_two_two(tmp, arg, envi);
        waitpid(tmp, &status, WUNTRACED | WCONTINUED);
        disp_segaultf(status);
        return (1);
    }
    my_putstr(arg[0]);
    my_putstr(": Command not found.\n");
}

void bultin_scnd_two(int tmp, char *filepath, char **arg, char **envi)
{
    if (tmp == 0) {
        if (execve(filepath, arg, envi) == -1) {
            my_putstr(arg[0]);
            my_putstr(": Exec format error. Wrong Architecture.\n");
            exit(0);
        }
    }
}