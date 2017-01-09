/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Mon Jan  9 19:49:01 2017 Joubert Miguel
*/

#include "get_next_line.h"

char	*my_strcat(char *dest, char *src)
{
  char  *res;
  int   i;
  int   write;

  res = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));
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

  if (a == 0)
    {
      k = 0;
      str = malloc(sizeof(char) * READ_SIZE + 1);
      *str = 0;
      a++;
    }
  j = 0;
  buffer = malloc(sizeof(char) * READ_SIZE + 1);
  while ((i = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[i] = 0;
      str = my_strcat(str, buffer);
      (j == 0) ? dest = malloc(sizeof(char) * strlen(str)) : 0;
      (j != 0) ? dest = my_strcat(dest, "\0") : 0;
      i += k;
      while (k != i)
	{
	  if (str[k] == 0)
	    {
	      dest = 0;
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
  dest = malloc(sizeof(char) * strlen(str));
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
  dest = 0;
  return (dest);
}

/*int	main(int ac, char **av)
{
  char	*s;
  int	fd;

  if (ac < 2)
    exit (84);
  fd = open(av[1], O_RDONLY);
  while (s = get_next_line(fd))
    {
      write(1, s, strlen(s));
      write(1, "\n", 1);
      free(s);
    }
}*/
