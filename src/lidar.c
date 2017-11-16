/*
** lidar.c for lidar in /home/durand_4/rendu/prog_elem/n4S/n4s_david/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Wed May  4 16:04:37 2016 loic durand
** Last update Thu May 26 16:22:39 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"
#include "my.h"

int	get_info_lidar(t_lid *lid)
{
  my_putstr("GET_INFO_LIDAR\n");
  if (pars_lidar(lid) == N4S_ERR)
    return (N4S_ERR);
  lid->ave_front = (lid->lidar_info[12] + lid->lidar_info[13]
                    + lid->lidar_info[14] + lid->lidar_info[15]
                    + lid->lidar_info[16]) / 5;
  return (N4S_OK);
}

int	pars_lidar(t_lid *lid)
{
  int	a;
  int	p;
  char	*buffer;
  char	**tab;

  p = 0;
  while (p != 32)
    {
      if ((buffer = get_next_line(N4S_OK)) == NULL)
	return (N4S_ERR);
      a = p = 0;
      while (buffer[a] != '\0' && p != 32)
	{
	  if (buffer[a] == '.')
	    p++;
	  a++;
	}
      if (p == 32)
	tab = my_str_to_wordtab(buffer, ':');
    }
  if (creat_tab_int(tab, lid) == N4S_ERR)
    return (N4S_ERR);
  return (N4S_OK);
}

int	creat_tab_int(char **tab, t_lid *lid)
{
  int	x;
  int	infos;

  x = 0;
  if (my_strcmp(tab[35], "Track Cleared") == N4S_OK)
    {
      if (car_stop(lid) == N4S_ERR)
	return (N4S_ERR);
    }
  if ((lid->lidar_info = malloc(sizeof(int) * 32)) == N4S_OK)
    return (N4S_ERR);
  while (x != 33)
    {
      infos = my_getnbr(tab[x + 3]);
      lid->lidar_info[x] = infos;
      x++;
    }
  return (N4S_OK);
}
