/*
** EPITECH PROJECT, 2018
** include functions
** File description:
** include functions
*/

#ifndef MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>

struct path {
    char *pwd;
};

typedef struct path path;


int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int check_number(char *str);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int nb_special(long nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
int low(char c);
int up(char c);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_str_isalpha(char *str);
char *my_str_islower(char *str);
char *my_str_isnum(char *str);
char *my_str_isprintable(char *str);
char *my_str_isupper(char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void *infin_add(char *nb1, char *nb2);
int my_str_taller(char const *s1, char const *s2);
char *big_nb(char *nb1, char *nb2);
char *small_nb(char *nb1, char *nb2);
int my_str_is_equal(char *str1, char *str2);
void my_put_infinadd(int ret, char *nb, int type);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
char **setenv_funct(char **arg, char **env);
int str_to_word_tab_two(char *str, char *str_two);
int len_tab(char **env);
void disp_env(char **env);
char **unsetenv_funct(char **arg, char **env);
char **new_env_tab(char **tmp_env, char **env);
int count_word(char *str);
char *rewrite_tab(char *str);
char **create_arg_null(char **arg);
char **create_arg_two(int i, int k, char *str, char **arg);
char **create_arg(char **arg, char *str);
int str_to_word_tab_two_two(char *str, char *str_two);
int str_to_word_tab_two(char *str, char *str_two);
int str_to_word_tab_snd(char *str, char *str_two);
int str_to_word_tab(char *str, char *str_two);
char **function_cdirectory_three(path *pth, char **env, char *home_str);
char **function_cdirectory_four(path *pth, char **env, char *tmp_oldpwd);
char **function_cdirectory_five(char **arg, path *pth, char **env);
int function_cdirectory_six(char **arg);
int function_cdirectory(char **arg, char **env, char *home_str,
struct path *pth);
char **distrib_builtin(char **arg, char **env, char *home_str,
struct path *pth);
void disp_segaultf(int status);
void bultin_two_two(int tmp, char **arg, char **envi);
int bultin_two(char **arg, char **envi);
void bultin_scnd_two(int tmp, char *filepath, char **arg, char **envi);
int line_user(char **env);
int line_home(char **env);
int line_path(char **env);
void disp_env(char **env);
int my_getenv_nb_path(char **envi, int i);
char **my_getenv_filepath(int i, int nb_path, char **envi);
char **my_getenv(char **envi);
int line_oldpwd(char **env);
int line_pwd(char **env);
int function_cdirectory_two(char **env, char **arg);
int bultin_scnd(char **filepath, char **envi, char **arg);
int bultin(char **arg, char **envi);
int test_bultin(char **arg);
char **new_env(char **env, char **envi);
void main_three(char **arg, char **envi);
char **rewrite_env_two(char **tmp_env, char **env);
int len_before_equal(char *str);
int len_tab(char **env);
char **new_env_tab(char **tmp_env, char **env);
void rewrite_line_tab_two(char **arg, int i, char **env, char *tmp_env);
void rewrite_line_tab(char **arg, int i, char **env, char *tmp_env);
char **rewrite_env_two_two(char **env, char **arg);
char **rewrite_env(char **env, char **arg);
char **setenv_funct_two(char **arg, char **env);
char **setenv_funct_three(char **arg, char **env);
char **setenv_funct(char **arg, char **env);

#endif
