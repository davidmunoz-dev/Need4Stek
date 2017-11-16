/*
** ia.c for checkpoint in /home/durand_4/rendu/prog_elem/n4S/CPE_2015_n4s/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Wed May 25 11:51:33 2016 loic durand
** Last update Thu May 26 15:55:10 2016 David Munoz
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"
#include "my.h"


void	my_putstrr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      write(2, &str[a], 1);
      a++;
    }
}

int	get_msg(t_lid *lid)
{
  char	*msg;

  if ((msg = get_next_line(0)) == NULL)
    return (N4S_ERR);
  if ((msg[0] >= '3' && msg[0] <= '9') || msg[0] == '0')
    {
      my_putstrr(msg);
      my_putstrr("\n");
      free(lid);
      my_putstr("STOP_SIMULATION\n");
    }
  else
    {
      if (checkpoint_info(msg, lid) == N4S_ERR)
	return (N4S_ERR);
    }
  free(msg);
  return (N4S_OK);
}

int	checkpoint_info(char *msg, t_lid *lid)
{
  int	a;
  int	b;
  char	*info;

  a = -1;
  b = 3;
  while (b != N4S_OK)
    {
      if (msg[++a] == ':')
	b--;
    }
  if ((info = malloc(50)) == NULL)
    return (N4S_ERR);
  b = -1;
  while (msg[++a] != ':' && msg[a] != '\0')
    info[++b] = msg[a];
  info[++b] = '\0';
  if (my_strcmp(info, "Track Cleared") == N4S_OK)
    {
      if (car_stop(lid) == N4S_ERR)
      return (N4S_ERR);
    }
  free(info);
  return (N4S_OK);
}
