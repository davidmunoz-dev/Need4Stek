/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/durand_4/rendu/prog_elem/n4S/CPE_2015_n4s/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Thu May 19 09:54:08 2016 loic durand
** Last update Thu May 26 15:55:37 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "n4s.h"

int	cpy_word(char *str, char c)
{
  int	i;
  int	cpy;
  char	prev;

  prev = c;
  i = cpy = 0;
  while (str && str[i])
    {
      if ((prev == c) && (str[i] != c))
	cpy++;
      prev = str[i];
      i++;
    }
  return (cpy);
}

char	*copy(char *str, char *dest, int start, char c)
{
  int	i;

  i = 0;
  while ((str[start] != c) && (str[start]))
    {
      dest[i] = str[start];
      i++;
      start++;
    }
  dest[i] = '\0';
  return (dest);
}

int	cpy_letter(char *str, int start, char c)
{
  int	i;

  i = 0;
  while ((str[start] != c) && (str[start]))
    {
      start++;
      i++;
    }
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	j;
  char	prev;
  char	**tab;

  i = j = 0;
  if ((tab = malloc((cpy_word(str, c) + 1) * sizeof(*tab))) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  prev = c;
  while (str && str[i])
    {
      if ((prev == c) && (str[i] != c))
	{
	  if ((tab[j] = malloc((cpy_letter(str, i, c) + 1) * sizeof(**tab)))
	      == NULL)
	    return (cerr_msg(INT_ERR, MALL_ERR));
	  copy(str, tab[j], i, c);
	  j++;
	}
      prev = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
