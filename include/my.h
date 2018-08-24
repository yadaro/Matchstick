/*
** my.h for my.h in /home/Yadaro/CPE_2016_matchstick
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Mon Feb 20 12:41:31 2017 Yadaro YUN
** Last update Sun Jun 11 16:57:48 2017 Yadaro YUN
*/

#ifndef _MY_H_
# define _MY_H_

# define ERR_EXE1 "Need 2 arguments\n"
# define ERR_EXE2 "Put only digits\n"
# define ERR_EXE3 "Invalid argument(s)\n"
# define ERR_POS "Error: invalid input (positive number expected)\n"
# define ERR_ZER "Error: you have to remove at least one match\n"
# define ERR_SUP "Error: you cannot remove more that "
# define ERR_SUP2 " matches per turn\n"
# define ERR_ENO "Error: not enough matches on this line\n"
# define ERR_RAN "Error: this line is out of range\n"

# define RMV "Player removed "
# define AI_RMV "AI removed "
# define RMV2 " match(es) from line "
# define AI_TURN "\nAI's turn...\n"
# define PLAYER_TURN "\nYour turn:\n"
# define MATCHES "Matches: "
# define LINE "Line: "
# define LOST "You lost, too bad...\n"
# define WIN "I lost... snif... but I'll get you next time!!\n"

typedef struct		s_chars
{
  char			ch;
  struct s_chars	*next;
}			t_chars;

typedef struct		s_wd
{
  int			i;
  int			x;
  int			y;
  char			**tab;
}			t_wd;

typedef struct		s_game
{
  int			pipe;
  int			line;
  int			match;
  int			a1;
  int			a2;
  int			r_l;
  int			r_m;
}			t_game;

/*
**	Lib
*/

int	my_putchar(char c);
int	my_putstr(char *s);
int	my_atoi(char *str);
int	my_put_nbr(int nb);
int	my_errchar(char c);
int	my_errstr(char *s);
char	**my_str_to_wordtab(char *s, char param);
void	my_showtab(char **str);
int	my_strlen(char *s);
int	my_str_isnum(const char *str);
char	*get_next_line(const int fd);

/*
**	Player Game
*/

int	get_line(char **map, t_game *g);
int	the_game(char **map, char **av);

/*
**	AI Game
*/

void	ai_turn(char **board, t_game *g);

/*
**	Manip Pipe
*/

int	count_pipe(char **board, int y);
char	**put_the_pipes(char **map, int len);
void	remove_pipe(char **board, int y, int pipe);

/*
**	Error Messages
*/

void	error_match(char **map, t_game *g);
void	check_error(char **map, t_game *g);

#endif		/* !_MY_H_ */
