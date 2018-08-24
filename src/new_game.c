/*
** new_game.c for   in /home/Yadaro/CPE_2016_matchstick
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sat Jun 10 19:03:12 2017 Yadaro YUN
** Last update Sun Jun 11 16:58:47 2017 Yadaro YUN
*/

#include <stdlib.h>
#include "my.h"


static void	result(char **map, t_game *g)
{
  my_putstr(RMV);
  my_put_nbr(g->match);
  my_putstr(RMV2);
  my_put_nbr(g->line);
  my_putchar('\n');
  remove_pipe(map, g->line, g->match);
  my_showtab(map);
}

static int		get_match(char **map, t_game *g)
{
  char		*s;

  my_putstr(MATCHES);
  s = get_next_line(0);
  g->match = my_atoi(s);
  if (g->match < 0)
    error_match(map, g);
  if (s == NULL)
    return (0);
  check_error(map, g);
  free(s);
  while (g->r_m > 0)
    return (g->r_m--);
  g->pipe = g->pipe - g->match;
  result(map, g);
  if (g->pipe == 0)
    return (2);
  ai_turn(map, g);
  return ((g->pipe == 0) ? 1 : 3);
}

int		get_line(char **map, t_game *g)
{
  char		*s;

  my_putstr(LINE);
  s = get_next_line(0);
  if (s == NULL)
    return (0);
  if ((g->line = my_atoi(s)) < 0 || my_str_isnum(s) == 0)
    {
      my_putstr(ERR_POS);
      g->r_l++;
      get_line(map, g);
    }
  else if (g->line < 1 || g->line > g->a1)
    {
      my_putstr(ERR_RAN);
      g->r_l++;
      get_line(map, g);
    }
  free(s);
  while (g->r_l > 0)
    return (g->r_l--);
  return (get_match(map, g));
}

static void	init_game(t_game *g)
{
  g->pipe = 0;
  g->line = 0;
  g->match = 0;
  g->r_m = 0;
  g->r_l = 0;
}

int		the_game(char **map, char **av)
{
  int		i;
  t_game	*g;

  if ((g = malloc(sizeof(t_game))) == NULL)
      return (84);
  init_game(g);
  g->a1 = my_atoi(av[1]);
  g->a2 = my_atoi(av[2]);
  g->pipe = g->a1 * g->a1;
  while (g->pipe > 0)
    {
      my_putstr(PLAYER_TURN);
      if ((i = get_line(map, g)) == 0)
	  return (i);
    }
  return (i);
}
