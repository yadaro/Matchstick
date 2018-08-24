/*
** error_message.c for matchstick in /home/Yadaro/CPE_2016_matchstick
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Feb 24 17:39:19 2017 Yadaro YUN
** Last update Sun Jun 11 15:46:01 2017 Yadaro YUN
*/

#include "my.h"

void	error_match(char **map, t_game *g)
{
  my_putstr(ERR_POS);
  g->r_m++;
  get_line(map, g);
}

void	check_error(char **map, t_game *g)
{
  if (g->match == 0)
    {
      my_putstr(ERR_ZER);
      g->r_m++;
      get_line(map, g);
    }
  else if (g->match > g->a2)
    {
      my_putstr(ERR_SUP);
      my_put_nbr(g->a2);
      my_putstr(ERR_SUP2);
      g->r_m++;
      get_line(map, g);
    }
  else if (g->match > count_pipe(map, g->line))
    {
      my_putstr(ERR_ENO);
      g->r_m++;
      get_line(map, g);
    }
}
