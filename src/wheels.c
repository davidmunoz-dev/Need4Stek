/*
** wheels.c for wheels in /home/durand_4/rendu/prog_elem/n4S/n4s_david/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Wed May 11 17:38:49 2016 loic durand
** Last update Thu May 26 16:14:56 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"
#include "my.h"

int	turn_wheels_check(t_lid *lid)
{
  if (lid->lidar_info[15] > 600
      || (lid->lidar_info[0] > 250
	  || lid->lidar_info[31] > 250))
    {
      if (far_to_wall(lid) == N4S_ERR)
	return (N4S_ERR);
    }
  else if (lid->lidar_info[15] <= 600 ||
	   (lid->lidar_info[0] < 250 ||
	    lid->lidar_info[31] < 250))
    {
      if (near_to_wall(lid) == N4S_ERR)
	return (N4S_ERR);
    }
  return (N4S_OK);
}

int	near_to_wall(t_lid *lid)
{
  my_putstr("CAR_FORWARD:0.15\n");
  if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid)) == N4S_ERR)
    return (N4S_ERR);
  if (lid->lidar_info[31] > lid->lidar_info[0])
    {
      my_putstr("WHEELS_DIR:-0.45\n");
      if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid) == N4S_ERR))
	return (N4S_ERR);
    }
  else if (lid->lidar_info[31] < lid->lidar_info[0])
    {
      my_putstr("WHEELS_DIR:0.45\n");
      if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid) == N4S_ERR))
	return (N4S_ERR);
    }
  return (N4S_OK);
}

int	far_to_wall(t_lid *lid)
{
  my_putstr("CAR_FORWARD:0.25\n");
  if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid)) == N4S_ERR)
    return (N4S_ERR);
  if (lid->lidar_info[31] < lid->lidar_info[0])
    {
      my_putstr("WHEELS_DIR:0.2\n");
      if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid)) == N4S_ERR)
	return (N4S_ERR);
    }
  else if (lid->lidar_info[31] > lid->lidar_info[0])
    {
      my_putstr("WHEELS_DIR:-0.2\n");
      if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid)) == N4S_ERR)
	return (N4S_ERR);
    }
  return (N4S_OK);
}

int	turn_wheels(t_lid *lid)
{
  if (get_info_lidar(lid) == N4S_ERR)
    return (N4S_ERR);
  if (lid->lidar_info[15] > 1200
      && (lid->lidar_info[0] > 350
	  && lid->lidar_info[31] > 350))
    {
      my_putstr("CAR_FORWARD:0.7\n");
      if (get_msg(lid) == N4S_ERR)
	return (N4S_ERR);
      my_putstr("WHEELS_DIR:0\n");
      if ((get_msg(lid) == N4S_ERR) || (get_info_lidar(lid)) == N4S_ERR)
	return (N4S_ERR);
    }
  else if (lid->lidar_info[15] < 1200
	   || (lid->lidar_info[0] <= 350
	       || lid->lidar_info[31] <= 350))
    {
      if (turn_wheels_check(lid) == N4S_ERR)
	return (N4S_ERR);
    }
  return (N4S_OK);
}
