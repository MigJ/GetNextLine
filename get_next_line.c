/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Tue Jan  3 19:59:39 2017 Joubert Miguel
*/

#include "get_next_line.h"

size_t	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char	*remalloc(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = malloc(sizeof(char) * my_strlen(str) + 2);
  while (str[i] != 0)
    {
      tmp[i] = str[i];
      i++;
    }
  free(str);
  tmp[i] = 0;
  return (tmp);
}

char	*get_next_line(const int fd)
{
  static char buffer[READ_SIZE];
  char	*dest;
  int	i;

  i = 0;
  dest = malloc(sizeof(char) + 1);
  *dest = 0;
  while (read(fd, buffer, 1) > 0 && *buffer != '\n')
    {
      dest[i++] = *buffer;
      dest[i] = 0;
      dest = remalloc(dest);
    }
  dest[i] = 0;
  return (dest);
}
