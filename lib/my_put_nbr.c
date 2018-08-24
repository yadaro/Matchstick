/*
** my_put_nbr2.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 17:14:25 2017 Yadaro YUN
** Last update Sun Jun 11 17:14:41 2017 Yadaro YUN
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 0 && nb <= 9)
      my_putchar(nb + '0');
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      nb = nb % 10;
      my_putchar(nb + '0');
    }
  return (0);
}
