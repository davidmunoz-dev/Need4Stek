/*
** main.c for main in /home/durand_4/rendu/prog_elem/n4S/CPE_2015_n4s/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Fri May 20 18:12:06 2016 loic durand
** Last update Thu May 26 15:59:40 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"
#include "my.h"

int	go_car(t_lid *lid)
{
  while (lid->lidar_info[15] > 300
	 && (lid->lidar_info[31] > 150
	     && lid->lidar_info[0] > 150))
    {
      if (turn_wheels(lid) == N4S_ERR)
	return (N4S_ERR);
    }
  if (car_backwards(lid) == N4S_ERR)
    return (N4S_ERR);
  if (go_car(lid) == N4S_ERR)
    return (N4S_ERR);
  return (0);
}

int	main(void)
{
  t_lid *lid;

  if ((lid = malloc(sizeof(t_lid *))) == 0)
    return (N4S_ERR);
  my_putstr("START_SIMULATION\n");
  if (get_msg(lid) == N4S_ERR ||
      get_info_lidar(lid) == N4S_ERR)
    return (N4S_ERR);
  my_putstr("CAR_FORWARD:0.5\n");
  if (get_msg(lid) == N4S_ERR ||
      go_car(lid) == N4S_ERR)
    return (N4S_ERR);
  return (0);
}
