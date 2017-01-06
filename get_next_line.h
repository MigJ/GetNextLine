/*
** my.h for  in /home/joubert/delivery/CPE_2016_getnextline/include
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 17:01:30 2017 Joubert Miguel
** Last update Fri Jan  6 15:03:23 2017 Joubert Miguel
*/

#ifndef _get_next_line
#define _get_next_line

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define READ_SIZE 11

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
int   k;
int   tmp;
}t_GetnextFd;

#endif
