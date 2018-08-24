/*
** put_pipe.c for matchstick in /home/Yadaro/CPE_2016_matchstick
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Thu Feb 23 11:24:13 2017 Yadaro YUN
** Last update Sat Jun 10 18:35:40 2017 Yadaro YUN
*/

#include "my.h"

int	count_pipe(char **board, int y)
{
  int	x;
  int	d;

  d = 0;
  x = 0;
  while (board[y][x])
    {
      if (board[y][x] == '|')
	d++;
      x++;
    }
  return (d);
}

char	**put_the_pipes(char **map, int len)
{
  int	c;
  int	x;
  int	y;

  c = 0;
  x = len;
  y = 1;
  while (y <= len)
    {
      c = y - 1;
      while (c >= 0)
	{
	  map[y][x + c] = '|';
	  map[y][x - c] = '|';
	  c--;
	}
      y++;
    }
  return (map);
}

void	remove_pipe(char **board, int y, int pipe)
{
  int	x;
  int	d;

  d = 0;
  x = my_strlen(board[y]);
  while (board[y][x] != '|')
    x--;
  while (d < pipe)
    {
      board[y][x] = ' ';
      x--;
      d++;
    }
}
