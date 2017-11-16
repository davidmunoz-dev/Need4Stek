/*
** my.h for EXERCICE 2 in /home/munoz_d/rendu/Piscine_C_J09
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Oct  9 13:51:01 2015 munoz david
** Last update Thu May 26 16:22:15 2016 David Munoz
*/

# ifndef READ_SIZE
# define READ_SIZE (300)
# endif /* !READ_SIZE */

#ifndef MY_H_
# define MY_H_

/*
**	Librairie de base
*/
void	my_putchar(char c);
int	my_strcmp(char *s1, char *s2);
int	my_strlen (char *str);
int	my_getnbr(char *str);
int	my_putstr(char *str);

/*
**	Getnextline
*/
int     my_gnl_read(char *buffer, const int fd, int *i);
char    *my_gnl_strcpy(char *source, char c, int lenght_line);
char    *my_gnl_error(char *line, int i, int lenght_read, int lenght_line);
char    *get_next_line(const int fd);


#endif /* !MY_H_ */
