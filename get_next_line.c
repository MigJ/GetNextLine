/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Thu Jan 12 20:47:16 2017 Joubert Miguel
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_realloc(char *str)
{
  int	i;
  char	*dest;

  i = 0;
  while (str[i])
    i++;
  if ((dest = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  char  *res;
  int   i;
  int	j;
  int   write;

  j = i = 0;
  while (dest[i])
    i++;
  while (src[j])
    j++;
  if ((res = malloc(sizeof(char) * ((i + j + 1) * 100))) == NULL)
    return (NULL);
  i = -1;
  write = 0;
  while (dest[++i])
    res[write++] = dest[i];
  i = -1;
  while (src[++i])
    res[write++] = src[i];
  res[write] = '\0';
  return (res);
}

t_Static	my_read(t_Static S, const int fd)
{
  if (S.i > 0)
    {
      while ((S.i = read(fd, S.buffer, READ_SIZE)) > 0)
	{
	  S.buffer[S.i] = 0;
	  S.str = my_strcat(S.str, S.buffer);
	  S.i += S.k;
	  while (S.k != S.i)
	    {
	      if (S.str[S.k] == 0 || S.str[S.k] == '\n')
		{
		  S.dest = my_realloc(S.dest);
		  (S.str[S.k] == 0) ? S.dest = 0 : 0;
		  (S.str[S.k] == '\n') ? S.dest[S.j] = 0, S.k++ : 0;
		  return (S);
		}
	      S.dest = my_realloc(S.dest);
	      S.dest[S.j] = S.str[S.k];
	      S.j++, S.k++;
	    }
	}
    }
  return (S);
}

char	*get_next_line(const int fd)
{
  static t_Static	S;

  S.j = 0;
  if (fd < 0)
    return (NULL);
  if (S.a == 0)
    {
      S.i = 1;
      S.k = 0;
      if ((S.str = malloc(sizeof(char) * (READ_SIZE + 1) * 100)) == NULL)
	return (NULL);
      if ((S.dest = malloc(sizeof(char))) == NULL)
	return (NULL);
      *S.str = 0;
      S.a++;
    }
  if ((S.buffer = malloc(sizeof(char) * (READ_SIZE + 1) * 100)) == NULL)
    return (NULL);
  S = my_read(S, fd);
  if ((S.str[S.k] == 0 || S.str[S.k - 1] == '\n') && S.i > 0)
    return (S.dest);
  while (S.str[S.k])
    {
      if (S.str[S.k] == '\n')
	{
	  S.dest = my_realloc(S.dest);
	  S.dest[S.j] = 0;
	  S.k++;
	  return (S.dest);
	}
      S.dest = my_realloc(S.dest);
      S.dest[S.j] = S.str[S.k];
      S.j++, S.k++;
    }
  S.dest[S.j] = 0;
  return ((*S.dest == 0) ? NULL : S.dest);
}

/*int	main(int ac, char **av)
{
  char	*s;
  int	fd;

  if (ac < 2)
    exit (84);
  fd = open(av[1], O_RDONLY);
  while (s = get_next_line(0))
    {
      printf("%s\n", s);
      //write(1, s, strlen(s));
      //write(1, "\n", 1);
      free(s);
    }
}*/
