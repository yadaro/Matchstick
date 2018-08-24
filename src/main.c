/*
** main.c for matchstick in /home/Yadaro/CPE_2016_matchstick
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Mon Feb 20 12:46:38 2017 Yadaro YUN
** Last update Sun Jun 11 17:13:49 2017 Yadaro YUN
*/

#include <stdlib.h>
#include "my.h"

static char	**buffer_map(int x, int y, char **board, int *len)
{
  y = 0;
  x = 0;
  while (*len > 0 && y < *len + 2)
    {
      if ((board[y] = malloc(sizeof(char) * (*len * 2 + 2))) == NULL)
	return (NULL);
      x = 0;
      while (x < *len * 2 + 1)
	{
	  board[y][x] = '*';
	  if (y > 0 && y < *len + 1 && x > 0 && x < *len * 2)
	    board[y][x] = ' ';
	  x++;
	}
      board[y][x] = '\0';
      y++;
    }
  return (board);
}

static char	**generate_map(int len)
{
  char		**board;
  int		x;
  int		y;

  y = 0;
  x = 0;
  if ((board = malloc(sizeof(char *) * (len * 2 + 2))) == NULL)
    return (NULL);
  buffer_map(x, y, board, &len);
  board[len + 2] = NULL;
  board = put_the_pipes(board, len);
  my_showtab(board);
  return (board);
}

static int	error_main(int ac, char **av)
{
  if (ac != 3)
    {
      my_putstr(ERR_EXE1);
      return (84);
    }
  else if (my_str_isnum(av[2]) == 0 || my_str_isnum(av[1]) == 0)
    {
      my_putstr(ERR_EXE2);
      return (84);
    }

  else if (my_atoi(av[1]) <= 0 || my_atoi(av[1]) > 100 || my_atoi(av[2]) <= 0)
    {
      my_putstr(ERR_EXE3);
      return (84);
    }
  return (0);
}

static void	free_map(char **map)
{
  int		i;

  i = 0;
  while (map[i])
    {
      free(map[i]);
      ++i;
    }
}

int	main(int ac, char **av, char **board)
{
  int	end;

  if (ac == 3 && my_atoi(av[1]) > 0 && my_atoi(av[1]) <= 100 &&
      my_atoi(av[2]) > 0 && my_str_isnum(av[2]) != 0 &&
      my_str_isnum(av[1]) != 0)
    {
      board = generate_map(my_atoi(av[1]));
      if ((end = the_game(board, av)) == 2)
	{
	  my_putstr(LOST);
	  free_map(board);
	  return (2);
	}
      else if (end == 1)
	{
	  my_putstr(WIN);
	  free_map(board);
	  return (1);
	}
    }
  else
    error_main(ac,av);
  return (0);
}
