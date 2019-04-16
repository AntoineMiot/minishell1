/*
** EPITECH PROJECT, 2018
** Minishell1
** File description:
** Minishell
*/
#include "include/my.h"

int str_to_word_tab_two_two(char *str, char *str_two)
{
    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] != str_two[i]) {
            return (1);
        }
    }
    return (2);
}

int str_to_word_tab_two(char *str, char *str_two)
{
    int j;
    if (my_strlen(str) == my_strlen(str_two)) {
        j = str_to_word_tab_two_two(str, str_two);
        if (j == 1)
            return (1);
    } else if (my_strlen(str) != my_strlen(str_two)) {
        return (1);
    }
    return (0);
}

int str_to_word_tab_snd(char *str, char *str_two)
{
    for (int i = 0; i != my_strlen(str) - 1; i++) {
        if (str[i] != str_two[i]) {
            return (1);
        }
    }
    return (2);
}

int str_to_word_tab(char *str, char *str_two)
{
    int j;

    if (my_strlen(str) == my_strlen(str_two) + 1) {
        j = str_to_word_tab_snd(str, str_two);
        if (j == 1)
            return (1);
    } else if (my_strlen(str) != my_strlen(str_two) + 1) {
        return (1);
    }
    return (0);
}