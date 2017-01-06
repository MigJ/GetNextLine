/*
** my.h for  in /home/joubert/delivery/CPE_2016_getnextline/include
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 17:01:30 2017 Joubert Miguel
** Last update Fri Jan  6 17:41:05 2017 Joubert Miguel
*/

#ifndef _GET_NEXT_LINE
#define _GET_NEXT_LINE

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define READ_SIZE 1

typedef struct s_Getnext
{
char	*buffer;
int   tmp;
int	j;
}t_Getnext;

typedef struct s_Static
{
char     *str;
int      i;
int      a;
}t_Static;

typedef struct s_StaticFd
{
char   buffer[READ_SIZE];
char   *str;
}t_StaticFd;

typedef struct s_GetnextFd
{
char  *dest;
int   tmp;
}t_GetnextFd;

int     my_ret_line(char *str, int i, int a);

char    *my_strcat(char *dest, char *src);

char    *remalloc(char *str, int size, int a, int i);

char    *get_next_line_fd_null(const int fd, int a, int k);

char    *get_next_line(const int fd);

#endif
