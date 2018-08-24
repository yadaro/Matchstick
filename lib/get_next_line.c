/*
** get_next_line.c for   in /home/Yadaro/CPE_2016_matchstick/lib
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sun Jun 11 14:59:49 2017 Yadaro YUN
** Last update Sun Jun 11 16:57:57 2017 Yadaro YUN
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static t_chars		*add_char(t_chars *list, char new_char)
{
	t_chars		*new_elem;
	t_chars		*tmp;
	
	tmp = list;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	if ((new_elem = malloc(sizeof(t_chars))) == NULL)
	{
		my_errstr("Malloc failed\n");
		return (NULL);
	}
	new_elem->next = NULL;
	new_elem->ch = new_char;
	if (tmp == NULL)
		return (new_elem);
	tmp->next = new_elem;
	return (list);
}

static void		store_line(t_chars *list, char *line, int size)
{
	t_chars		*tmp;
	int			i;
	
	i = 0;
	tmp = list;
	while ((tmp != NULL) && (i < size))
	{
		line[i] = tmp->ch;
		tmp = tmp->next;
		i = i + 1;
	}
}

char		*get_next_line(const int fd)
{
	t_chars	*char_list;
	int		size;
	char		buff;
	char		*line;
	
	if (read(fd, &buff, 1) <= 0)
		return (NULL);
	char_list = NULL;
	char_list = add_char(char_list, buff);
	size = 1;
	while ((read(fd, &buff, 1) > 0) && (buff != '\n'))
	{
		char_list = add_char(char_list, buff);
		size = size + 1;
	}
	if ((line = malloc(sizeof(char) * (size + 1))) == NULL)
	{
		my_errstr("Malloc Failed\n");
		return (NULL);
	}
	line[size] = '\0';
	store_line(char_list, line, size);
	return (line);
}
