/*
** main.c for  in /home/joubert/delivery/CPE_2016_getnextline
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 16:36:02 2017 Joubert Miguel
** Last update Fri Jan  6 17:41:16 2017 Joubert Miguel
*/

#include "get_next_line.h"

int	my_ret_line(char *str, int i, int a)
{
  if (a == 0)
    {
      if (str[i] == 0)
	return (848484);
      while (str[i] != '\n')
	{
	  if (str[i] == 0)
	    return (i);
	  i++;
	}
    }
  if (a == 1)
    {
      while (str[i] != 0)
	i++;
    }
  return ((a == 0) ? i + 1 : i);
}

char	*my_strcat(char *dest, char *src)
{
  char  *res;
  int   i;
  int   write;

  res = malloc(sizeof(char) * my_ret_line(dest, 0, 1)
	       + my_ret_line(src, 0, 1) + 1);
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

char	*remalloc(char *str, int size, int a, int i)
{
  char	*tmp;

  if (a == 0)
    {
      tmp = malloc(sizeof(char) * 1000);
      if (str == 0)
	return (tmp);
      while (str[i] != 0)
	{
	  tmp[i] = str[i];
	  i++;
	}
      tmp[i] = 0;
    }
  if (a == 1)
    {
      while (str[i + READ_SIZE] != 0)
	i++;
      size += i;
      while (i != size)
	i++;
      while (str[i] != 0)
	str[i++] = 0;
    }
  return ((a == 0) ? tmp : str);
}

char	*get_next_line_fd_null(const int fd, int a, int k)
{
  t_StaticFd	S;
  t_GetnextFd	G;

  if (a == 0 && fd != 0)
    {
      G.dest = malloc(sizeof(char) * READ_SIZE);
      S.str = malloc(sizeof(char) * READ_SIZE);
      while ((k = read(fd, G.dest, READ_SIZE)) > 0)
	{
	  G.tmp = k;
	  G.dest[READ_SIZE] = 0;
	  S.str = my_strcat(S.str, G.dest);
	}
      S.str = remalloc(S.str, G.tmp, 1, 0);
    }
  if (a != 0 && fd == 0)
    {
      while (read(fd, S.buffer, 1) > 0 && *S.buffer != '\n')
	{
	  G.dest = remalloc(G.dest, READ_SIZE, 0, 0);
	  G.dest[k++] = *S.buffer;
	  G.dest[k] = 0;
	}
    }
  return ((a == 0) ? S.str : G.dest);
}

char	*get_next_line(const int fd)
{
  t_Getnext	G;
  static t_Static	S;

  G.tmp = G.j = 0;
  (S.a == 0 && fd != 0) ? S.str = get_next_line_fd_null(fd, S.a, 0), S.a++ : 0;
  if (S.a != 0 && fd != 0)
    {
      G.tmp = S.i;
      if ((S.i = my_ret_line(S.str, S.i + 1, 0)) == 848484)
	{
	  G.buffer = 0;
	  return (G.buffer);
	}
      G.buffer = malloc(sizeof(char) * (S.i - G.tmp));
      while (G.tmp < S.i)
	{
	  G.buffer[G.j] = S.str[G.tmp];
	  G.tmp++, G.j++;
	}
      G.buffer[G.j - 1] = 0;
    }
  else
    G.buffer = get_next_line_fd_null(fd, 1, 0);
  return (G.buffer);
}

/*int	main(int ac, char **av)
{
  char	*s;
  int	fd;

  if (ac < 2)
    exit (84);
  fd = open(av[1], O_RDONLY);
  while ((s = get_next_line(fd)) != 0)
    {
      write(1, s, strlen(s));
      write(1, "\n", 1);
      free(s);
    }
}*/
