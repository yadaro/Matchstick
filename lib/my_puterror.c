/*
** my_puterror2.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 17:15:47 2017 Yadaro YUN
** Last update Sun Jun 11 17:16:07 2017 Yadaro YUN
*/

#include <unistd.h>
#include "my.h"

int	my_errchar(char c)
{
  if (write (2, &c, 1) == -1)
    return (84);
  return (0);
}

int	my_errstr(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (84);
  while (s[i] != '\0')
    {
      my_errchar(s[i]);
      i++;
    }
  return (84);
}
