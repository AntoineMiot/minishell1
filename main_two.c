/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

int count_word(char *str)
{
    int space = 0;
    int nb_word = 0;

    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] > 32 && str[i] < 127 && space == 0) {
            nb_word++;
            space = 1;
        } else if (str[i] == 32 && str[i + 1] >= 32 && str[i + 1] < 127)
            space = 0;
    }
    return (nb_word);
}

char *rewrite_tab(char *str)
{
    for (int g = 0; str[g] != '\n'; g++) {
        if (str[g] == 9)
            str[g] = 32;
    }
}

char **create_arg_null(char **arg)
{
    arg = malloc(sizeof(char*));
    arg[0] = NULL;
    return (arg);
}

char **create_arg_two(int i, int k, char *str, char **arg)
{
    int z = 0;

    for (z; str[z] == 32; z++);
    for (z; str[z] != '\n'; z++) {
        for (z; str[z] == 32 && str[z+1] == 32; z++);
        if (str[z] != 32 && str[z] != '\0' && str[z] != '\n') {
            arg[k][i] = str[z];
            i++;
        } else if (str[z] == 32 && str[z+1] != ' ' && str[z+1] != '\0'
        && str[z+1] != '\n') {
            arg[k][i] = '\0';
            k++;
            arg[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
            i = 0;
        }
    }
    arg[k][i] = '\0';
    arg[k+1] = NULL;
    return (arg);
}

char **create_arg(char **arg, char *str)
{
    int nb_word = count_word(str);
    int i = 0;
    int k = 0;

    if (nb_word == 0)
        return (create_arg_null(arg));
    rewrite_tab(str);
    arg = malloc(sizeof(char*) * (nb_word + 1));
    arg[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
    arg = create_arg_two(i, k, str, arg);
    return (arg);
}