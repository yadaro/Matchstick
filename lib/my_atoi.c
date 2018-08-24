/*
** my_atoi.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 15:04:29 2017 Yadaro YUN
** Last update Sun Jun 11 15:14:39 2017 Yadaro YUN
*/

#include <stdlib.h>
#include "my.h"

int	my_atoi(char *s)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  if (s == NULL)
    return (84);
  while (s[i])
    {
      nb = nb * 10 + s[i] - 48;
      ++i;
    }
  return (nb);
}
