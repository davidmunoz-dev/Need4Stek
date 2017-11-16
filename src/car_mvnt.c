/*
** car_mvnt.c for car_mvnt in /home/durand_4/rendu/prog_elem/n4S/CPE_2015_n4s/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Wed May 18 20:28:32 2016 loic durand
** Last update Thu May 26 16:23:08 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"
#include "my.h"

int	car_backwards(t_lid *lid)
{
  my_putstr("WHEELS_DIR:0\n");
  if (get_msg(lid) == N4S_ERR)
    return (N4S_ERR);
  my_putstr("CAR_BACKWARDS:0.3\n");
  if (get_msg(lid) == N4S_ERR)
    return (N4S_ERR);
  while (lid->ave_front < 500)
    {
      if (get_info_lidar(lid) == N4S_ERR)
	return (N4S_ERR);
    }
  return (N4S_OK);
}

int	car_stop(t_lid *lid)
{
  my_putstr("CAR_FORWARD:0\n");
  if (get_msg(lid) == N4S_ERR)
    return (N4S_ERR);
  my_putstr("CYCLE_WAIT:10\n");
  if (get_msg(lid) == N4S_ERR)
    return (N4S_ERR);
  free(lid);
  my_putstr("STOP_SIMULATION\n");
  return (N4S_OK);
}
