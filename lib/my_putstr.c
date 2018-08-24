/*
** my_putstr.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 15:38:56 2017 Yadaro YUN
** Last update Sun Jun 11 16:27:18 2017 Yadaro YUN
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_putchar(char c)
{
  if (write (1, &c, 1) == -1)
    return (84);
  return (0);
}

int	my_putstr(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (84);
  while (s[i])
    {
      my_putchar(s[i]);
      i++;
    }
  return (0);
}
