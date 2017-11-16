/*
** cerr_err.c for cerr_err in /home/durand_4/rendu/prog_elem/n4S/CPE_2015_n4s/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Thu May 19 09:46:53 2016 loic durand
** Last update Thu May 26 15:56:35 2016 David Munoz
*/

#include <unistd.h>
#include <stdlib.h>
#include "n4s.h"
#include "my.h"

void	*cerr_msg(char *log, char *info)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (NULL);
}
