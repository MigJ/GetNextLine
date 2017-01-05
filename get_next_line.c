/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Thu Jan  5 18:58:42 2017 Joubert Miguel
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

char	*remalloc(char *str, int size)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = malloc(sizeof(char) * (my_strlen(str) + size + 1));
  while (str[i] != 0)
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = 0;
  return (tmp);
}

int	my_ret_line(char *str, int i)
{
  if (str[i] == 0)
    return (848484);
  while (str[i] != '\n')
    {
      if (str[i] == 0)
	return (848484);
      i++;
    }

  return (i + 1);
}

char	*get_next_line_fd_null(const int fd)
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
      dest = remalloc(dest, READ_SIZE);
    }
  dest[i] = 0;
  return (dest);
}

char	*get_next_line(const int fd)
{
  char	*buffer;
  static char	*str;
  static int	i;
  int	tmp;
  static int	a;
  int	j;

  j = 0;
  if (a == 0 && fd != 0)
    {
      buffer = malloc(sizeof(char) * READ_SIZE);
      str = malloc(sizeof(char) * READ_SIZE);
      while (read(fd, buffer, READ_SIZE) != 0)
	{
	  buffer[READ_SIZE] = 0;
	  str = (*str != 0) ? strcat(str, buffer) : buffer;
	  str = remalloc(str, READ_SIZE);
	}
      a++;
    }
  if (a != 0 && fd != 0)
    {
      tmp = i;
      if ((i = my_ret_line(str, i + 1)) == 848484)
	{
	  buffer = 0;
	  return (buffer);
	}
      buffer = malloc(sizeof(char) * (i - tmp));
      while (tmp < i)
	{
	  buffer[j] = str[tmp];  
	  tmp++, j++;
	}
      buffer[j - 1] = 0;
    }
  else
    buffer = get_next_line_fd_null(fd);
  //write(1, str, my_strlen(str));
  return (buffer);
}

/*int	main(int ac, char **av)
{
  char	*s;
  int	fd;

  fd = open(av[1], O_RDONLY);
  while ((s = get_next_line(fd)) != 0)
    {
      write(1, s, my_strlen(s));
      write(1, "\n", 1);
      free(s);
    }
    }*/
