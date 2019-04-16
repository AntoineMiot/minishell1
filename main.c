/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

char **main_two(char *str, char **envi, char *home_str, struct path *pth)
{
    char **arg;

    arg = create_arg(arg, str);
    if (len_tab(arg) != 0) {
        if (test_bultin(arg) == 0) {
            envi = distrib_builtin(arg, envi, home_str, pth);
        } else {
            main_three(arg, envi);
        }
    }
    return (envi);
}

char **create_env(char **envi)
{
    char cwd[PATH_MAX];

    envi = malloc(sizeof(char *) * 2);
    envi[0] = my_strcat("PWD=", getcwd(cwd, sizeof(cwd)));
    envi[1] = NULL;
    return (envi);
}

int main(int ac, char **av, char **envi)
{
    char *str = NULL;
    size_t size;
    char *home_str;
    struct path *pth = malloc(sizeof(struct path));

    if (len_tab(envi) != 0)
        home_str = my_strcpy(home_str, envi[line_home(envi)]);
    else
        envi = create_env(envi);
    while (1) {
        if (isatty(0))
            my_putstr("$>");
        if (getline(&str, &size, stdin) != -1)
            envi = main_two(str, envi, home_str, pth);
        else
            return (0);
    }
    return (0);
}
