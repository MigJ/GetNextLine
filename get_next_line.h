/*
** my.h for  in /home/joubert/delivery/CPE_2016_getnextline/include
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 17:01:30 2017 Joubert Miguel
** Last update Mon Jan  9 19:48:43 2017 Joubert Miguel
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

#define READ_SIZE 23

char    *my_strcat(char *dest, char *src);

char    *get_next_line(const int fd);

#endif
