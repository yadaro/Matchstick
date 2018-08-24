/*
** my_str_to_wordtab.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 18:41:46 2017 Yadaro YUN
** Last update Sun Jun 11 18:42:42 2017 Yadaro YUN
*/

#include <stdlib.h>
#include "my.h"

static int	len(const char *s, char param)
{
  int		i;

  i = 0;
  while (s[i] && s[i] != param)
    ++i;
  return (i + 1);
}

static int	nb_param(const char *s, char param)
{
  int		i;
  int		r;

  i = 0;
  r = 1;
  while (s[i])
    {
      if (s[i] == param && i > 1
	  && s[i - 1] && s[i - 1] != param)
	++r;
      ++i;
    }
  return (r + 2);
}

static void	init_wd(t_wd *vr)
{
  vr->x = 0;
  vr->y = 0;
  vr->i = 0;
}

static char	**free_and_ret(t_wd *vr)
{
  char		**temp;

  temp = vr->tab;
  free(vr);
  return (temp);
}

char	**my_str_to_wordtab(char *s, char param)
{
  t_wd	*vr;

  if ((vr = malloc(sizeof(t_wd))) == NULL
      || (vr->tab = malloc(sizeof(char *) * (nb_param(s, param) + 1))) == NULL)
    return (NULL);
  init_wd(vr);
  while (s[vr->i] != '\0')
    {
      if ((vr->tab[vr->y] = malloc(sizeof(char)
				   * (len(&s[vr->i], param)))) == NULL)
	return (NULL);
      while (s[vr->i] != param && s[vr->i] != '\0')
	{
	  vr->tab[vr->y][vr->x] = s[vr->i];
	  ++vr->x;
	  ++vr->i;
	}
      while (s[vr->i] && s[vr->i] == param)
	++vr->i;
      vr->tab[vr->y][vr->x] = '\0';
      vr->x = 0;
      ++vr->y;
    }
  vr->tab[vr->y] = NULL;
  return (free_and_ret(vr));
}
