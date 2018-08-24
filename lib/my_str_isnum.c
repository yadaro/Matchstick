/*
** isnum.c for my_str_isnum in /home/Yadaro/CPE_2016_matchstick/Lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Feb 24 19:33:15 2017 Yadaro YUN
** Last update Sun Jun 11 16:55:40 2017 Yadaro YUN
*/

#include "my.h"

int	my_str_isnum(const char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 1;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	{
	  res = 0;
	  i++;
	}
    }
  return (res);
}
