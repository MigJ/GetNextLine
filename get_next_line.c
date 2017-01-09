/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Mon Jan  9 18:38:09 2017 Joubert Miguel
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
  static char *buffer;
  char *dest;
  static int a;
  static int k;
  int	i;
  int	tmp;

  if (a == 0)
    {
      k = 0;
      buffer = malloc(sizeof(char) * READ_SIZE + 1);
      str = malloc(sizeof(char) * READ_SIZE + 1);
      *str = 0;
      while ((i = read(fd, buffer, READ_SIZE)) > 0)
	{
	  tmp = i;
	  buffer[tmp] = 0;
	  str = my_strcat(str, buffer);
	}
      a++;
    }
  if (a != 0)
    {
      i = 0;
      dest = malloc(sizeof(char) * tmp);
      while (str[k] != 0)
	{
	  if (str[k] == '\n')
	    {
	      dest[i] = 0;
	      k++;
	      return (dest);
	    }
	  dest[i] = str[k];
	  i++, k++;
	}
    }
  (str[k] == 0) ? dest = 0 : 0;
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
