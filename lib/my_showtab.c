/*
** my_showtab.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sat Jun 10 21:22:44 2017 Yadaro YUN
** Last update Sun Jun 11 18:43:24 2017 Yadaro YUN
*/

#include "my.h"

void	my_showtab(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i++;
    }
}
