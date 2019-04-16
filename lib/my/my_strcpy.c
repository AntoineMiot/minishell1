/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = my_strlen(src);

    dest = malloc(sizeof(char) * (i+1));
    for (int j = 0; j != i; j++) {
        dest[j] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}
