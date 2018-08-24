/*
** strlen.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 15:01:13 2017 Yadaro YUN
** Last update Sun Jun 11 16:53:37 2017 Yadaro YUN
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (-1);
  while (s[i])
    i++;
  return (i);
}
