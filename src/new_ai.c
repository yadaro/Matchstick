/*
** new_ai.c for   in /home/Yadaro/CPE_2016_matchstick
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sat Jun 10 20:27:43 2017 Yadaro YUN
** Last update Sun Jun 11 17:06:12 2017 Yadaro YUN
*/

#include <time.h>
#include <stdlib.h>
#include "my.h"

static int	find_pipe(char **board)
{
  int		i;
  int		p;

  i = 1;
  p = 0;
  while (!p)
    {
      if ((p = count_pipe(board, i)) > 0)
	return (i);
      i++;
    }
  return (0);
}

static void	ai_result(int pipe, int line)
{
  my_putstr(AI_RMV);
  my_put_nbr(pipe);
  my_putstr(RMV2);
  my_put_nbr(line);
  my_putchar('\n');
}

void	ai_turn(char **board, t_game *g)
{
  int	line;
  int	p;
  int 	i;

  p = 0;
  my_putstr(AI_TURN);
  line = find_pipe(board);
  i = 0;
  while (p == 0)
    {
      srand(time(NULL) * i);
      if (((p = (rand() % count_pipe(board, line))) == 0) ||
	 (p > g->a2))
	p = 1;
      i++;
    }
  if ((count_pipe(board, line) == 3))
    p = 2;
  g->pipe = g->pipe - p;
  remove_pipe(board, line, p);
  ai_result(p, line);
  my_showtab(board);
}
