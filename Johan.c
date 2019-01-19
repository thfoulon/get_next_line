/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Johan.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:07:37 by thfoulon          #+#    #+#             */
/*   Updated: 2019/01/19 10:07:40 by thfoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void name(char *s)
{

}

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

int ft_check(char *str)
{
  int i = 0;
  while (str[i] != '\n' && str[i])
    i++;
  if (str[i] == '\n')
    return (1);
  return (0);
}

void ft_strappend(char *s1, char *s2)
{
  char *new;
  int i = 0;
  int j = 0;
  if (s1 == NULL)
  {
    s1 = (char*)malloc(sizeof(*s2) * strlen(s2));
    s1 = s2;
    return(s1);
  }
  new = (char*)malloc(sizeof(*new) * (strlen(s1) + strlen(s2)) + 1);
  while (s1[i])
  {
    new[i] = s1[i];
    i++;
  }
  while (s2[j])
  {
    new[i] = s2[j];
    i++;
    j++;
  }
	s1 = (char*)malloc(sizeof(*s1) * strlen(new) + 1);
	s1[i] = '\0';
}

int get_next_line(int fd, char **s)
{
  int nb_lues = 1;
  int retour = 0;
  char buff[BUFF_SIZE + 1];
  static char *new = NULL;
  while (nb_lues > 0)
  {
    nb_lues = read(fd, buff, BUFF_SIZE);
    if (ft_check(buff) == 1)
      break;
		else if (new)
				ft_strappend(new, buff);
		else
			new = ft_strdup(buff);
  }
	if (ft_check(new) == 1)
		ft_coupcoup(new);
  s = &new;
  if (nb_lues < BUFF_SIZE)
    return (0);
  if (strlen(buff) == 0)
    return (-1);
  return (1);
}

int  main(int ac, char **av)
{
  int fd;
  char *line;
  if (ac == 2)
  {
    if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      printf("open(); error\n");
      return (-1);
    }
    printf("%d\n", get_next_line(fd, &line));
  }
  else if (ac == 3)
  {
    printf("%s\n", ft_strappend(av[1], av[2]));
  }
  else
    printf("arg error\n");
  return (0);
}
