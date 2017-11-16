/*
** n4s.h for n4s in /home/durand_4/rendu/prog_elem/n4S/CPE_2015_n4s/include
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Wed May 18 20:21:23 2016 loic durand
** Last update Thu May 26 15:56:44 2016 David Munoz
*/

#ifndef N4S_H_
# define N4S_H_

# define N4S_OK		0
# define N4S_ERR	-1
# define INT_ERR	"Internal error : "
# define MALL_ERR	"Malloc failed\n"

typedef struct s_lid
{
  int	*lidar_info;
  int	ave_front;
}		t_lid;


/*
** checkpoint.c
*/
int	get_msg(t_lid *lid);
int	checkpoint_info(char *msg, t_lid *lid);
void	my_putstrr(char *str);

/*
** lidar.c
*/
int	get_info_lidar(t_lid *lid);
int	pars_lidar(t_lid *lid);
int	creat_tab_int(char **tab, t_lid *lid);

/*
** wheels.c
*/
int	near_to_wall(t_lid *lid);
int	far_to_wall(t_lid *lid);
int	turn_wheels(t_lid *lid);
int	turn_wheels_check(t_lid *lid);

/*
** car_mvnt.c
*/
int	car_backwards(t_lid *lid);
int	car_stop(t_lid *lid);

/*
** cerr_err.c
*/
void	*cerr_msg(char *, char *);

/*
** my_str_to_wordtab.c
*/
int	cpy_word(char *, char);
char	*copy(char *, char *, int, char);
int	cpy_letter(char *,int, char);
char	**my_str_to_wordtab(char *, char);

#endif /* !N4S_H_ */
