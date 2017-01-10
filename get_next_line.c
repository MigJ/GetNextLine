/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Tue Jan 10 14:41:55 2017 Joubert Miguel
*/

#include "get_next_line.h"

size_t	my_strlen(char *str)
{
  size_t	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  char  *res;
  int   i;
  int   write;

  if ((res = malloc(sizeof(char) * ((my_strlen(dest) + my_strlen(src) + 1) * 100))) == NULL)
    exit (84);
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

char	*get_next_line(const int fd)
{
  static char *str;
  char *buffer;
  char *dest;
  static int a;
  static int k;
  int j;
  int	i;

  if (fd < 0)
    return (NULL);
  if (a == 0)
    {
      k = 0;
      if ((str = malloc(sizeof(char) * (READ_SIZE + 1) * 100)) == NULL)
	exit (84);
      *str = 0;
      a++;
    }
  j = 0;
  if ((buffer = malloc(sizeof(char) * (READ_SIZE + 1) * 100)) == NULL)
    exit (84);
  while ((i = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[i] = 0;
      str = my_strcat(str, buffer);
      if (j == 0)
	{
	  if ((dest = malloc(sizeof(char) * my_strlen(str) * 100)) == NULL)
	    exit (84);
	}
      (j != 0) ? dest = my_strcat(dest, "\0") : 0;
      i += k;
      while (k != i)
	{
	  if (str[k] == 0)
	    {
	      dest = NULL;
	      return (dest);
	    }
	  if (str[k] == '\n')
	    {
	      dest[j] = 0;
	      k++;
	      return (dest);
	    }
	  dest[j] = str[k];
	  j++, k++;
	}
    }
  if ((dest = malloc(sizeof(char) * my_strlen(str) * 100)) == NULL)
    exit (84);
  while (str[k])
    {
      if (str[k] == '\n')
	{
	  dest[j] = 0;
	  k++;
	  return (dest);
	}
      dest[j] = str[k];
      j++, k++;
    }
  dest = NULL;
  return (dest);
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
      write(1, s, strlen(s));
      write(1, "\n", 1);
      free(s);
    }
}*/
